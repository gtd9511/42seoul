/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:05:35 by sanghan           #+#    #+#             */
/*   Updated: 2023/01/09 14:51:44 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_key_in_env_list(char *key, t_env *env_list)
{
	t_env	*temp;

	if (!key)
		return (0);
	temp = env_list;
	while (temp)
	{
		if (ft_strncmp(temp->key, key, ft_strlen(key) + 1) == 0)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	is_valid_format_key(char *key)
{
	int	i;

	if (!(ft_isalpha(key[0]) || key[0] == '_'))
		return (0);
	i = 1;
	while (key[i])
	{
		if (!(ft_isalpha(key[i]) || key[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

void	update_value(char *key, char *value, t_env **env_list)
{
	t_env	*temp;

	if (!key || value)
		return ;
	temp = *env_list;
	while (temp)
	{
		if (ft_strncmp(temp->key, key, ft_strlen(key) + 1) == 0)
		{
			free(temp->value);
			temp->value = value;
		}
		temp = temp->next;
	}
}

void	execute_export(char *key, char *value, t_env *env_list)
{
	t_env	*node;

	if (is_key_in_env_list(key, env_list))
		update_value(key, value, &env_list);
	else
	{
		if (!(is_valid_format_key(key)))
		{
			free(key);
			free(value);
			return ;
		}
		node = make_env_node(key, value);
		if (!node)
			return ;
		env_list_add_node(&env_list, node);
	}
}

int	ft_export(char **cmd, t_env *env_list)
{
	int		i;
	int		j;
	char	*key;
	char	*value;

	if (cmd[1] == NULL)
		print_env_list(env_list);
	i = 1;
	while (cmd[i] != NULL) // export만 입력했을 때 목록 표시
	{
		j = 0;
		while (cmd[i][j] && cmd[i][j] != '=')
			j++;
		key = ft_substr(cmd[i], 0, j); // 할당 실패 했을 때 처리 여부  //일단 함수 안에서 널 체크 하는 정도로만 작성
		value = ft_substr(cmd[i], j + 1, ft_strlen(cmd[i]) - j - 1);
		execute_export(key, value, env_list);
		i++;
	}
	return (1);
}
