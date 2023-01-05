/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:05:38 by sanghan           #+#    #+#             */
/*   Updated: 2023/01/05 20:09:15 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*get_node(char *key, t_env *env_list)
{
	t_env	*temp;

	temp = env_list;
	while (temp)
	{
		if (ft_strncmp(temp->key, key, ft_strlen(key) + 1) == 0)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

void	delete_node(char *key, t_env **env_list)
{
	t_env	*temp;
	t_env	*del_node;

	temp = *env_list;
	del_node = get_node(key, *env_list);
	if (!del_node)
		return ;
	while (temp)
	{
		if (temp->next == del_node)
		{
			temp->next = del_node->next;
			free(del_node->key);
			free(del_node->value);
			free(del_node);
		}
		else
			temp = temp->next;
	}
}

int	ft_unset(t_parser_token *parser_token, t_env *env_list)
{
	int	i;

	if (parser_token->cmd->next->content == NULL)
		return (0);
	i = 1;
	while (parser_token->cmd->next->content)
	{
		if (is_key_in_env_list(cmd[i], env_list))
			delete_node(cmd[i], &env_list);
		i++;
	}
	return (1);
}
