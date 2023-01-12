/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:44:13 by sanghan           #+#    #+#             */
/*   Updated: 2023/01/06 13:44:56 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_redirection(t_list *lexer_token)
{
	while (lexer_token != NULL)
	{
		if (REDIR_IN <= lexer_token->label \
		&& lexer_token->label <= REDIR_DOUBLE_OUT)
		{
			if (lexer_token->next == NULL \
			|| lexer_token->next->label != NORMAL_STRING)
			{
				return (1);
			}
		}
		lexer_token = lexer_token->next;
	}
	return (0);
}

// 파이푸 두개 (| |) 연속으로 있으면 오류
int	check_double_pipe(t_list *lexer_token)
{
	if (lexer_token != NULL && lexer_token->label == PIPE)
		return (1);
	while (lexer_token != NULL)
	{
		if (lexer_token->label == PIPE)
		{
			if (lexer_token->next == NULL || lexer_token->next->label == PIPE)
			{
				return (1);
			}
		}
		lexer_token = lexer_token->next;
	}
	return (0);
}