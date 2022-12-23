/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:05:38 by sanghan           #+#    #+#             */
/*   Updated: 2023/01/04 15:09:57 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_unset(t_parser_token *parser_token, t_env *env_list)
{
	int	i;

	if (parser_token->cmd->next->content == NULL)
		return (0);
	i = 1;
	while (parser_token->cmd->next->content)
	{
		if 
	}
}
