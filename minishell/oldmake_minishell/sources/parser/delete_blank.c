/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_blank.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:44:20 by sanghan           #+#    #+#             */
/*   Updated: 2023/01/06 13:45:11 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	delete_blank(t_list **lexer_token)
{
	t_list	*prev;
	t_list	*temp;

	while ((*lexer_token) != NULL && (*lexer_token)->label == BLANK)
	{
		prev = *lexer_token;
		*lexer_token = (*lexer_token)->next;
		ft_lstdelone(prev, free);
	}
	temp = *lexer_token;
	prev = temp;
	while (temp != NULL)
	{
		if (temp->label == BLANK)
		{
			prev->next = temp->next;
			ft_lstdelone(temp, free);
			temp = prev->next;
			continue ;
		}
		prev = temp;
		temp = temp->next;
	}
}
