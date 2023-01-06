/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_odd_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:52:06 by sanghan           #+#    #+#             */
/*   Updated: 2023/01/06 13:53:11 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_odd_quote(t_list *lexer_token) // 0 : 짝수 따옴표, 1 : 홀수 따옴표
{
	int	len;

	while (lexer_token != NULL)
	{
		// 9 == AFTER_HEREDOC
		if (lexer_token->label % 9 == DOUBLE_QUOTE \
		|| lexer_token->label % 9 == SINGLE_QUOTE)
		{
			len = ft_strlen(lexer_token->content);
			if (len < 2)
				return (1);
			if (lexer_token->content[0] != lexer_token->content[len - 1])
				return (1);
		}
		lexer_token = lexer_token->next;
	}
	return (0);
}
