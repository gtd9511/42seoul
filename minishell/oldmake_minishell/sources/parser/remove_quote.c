/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:44:30 by sanghan           #+#    #+#             */
/*   Updated: 2023/01/06 13:45:54 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
// parser 2-1 -> 따옴표 지우기
void	remove_quote(t_list **lexer_token)
{
	t_list	*temp;

	temp = *lexer_token;
	while (temp != NULL)
	{
		if (temp->label % 9 == SINGLE_QUOTE || temp->label % 9 == DOUBLE_QUOTE)
		{
			ft_memmove(temp->content, temp->content + 1, \
			ft_strlen(temp->content) - 2);
			temp->content[ft_strlen(temp->content) - 2] = '\0';
			temp->label = 9 * (temp->label / 9);
		}
		temp = temp->next;
	}
}