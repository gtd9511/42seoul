/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:58:52 by kyoulee           #+#    #+#             */
/*   Updated: 2022/05/20 13:55:34 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_move;

	if (*lst == NULL || new == NULL)
	{
		if (*lst == NULL)
			*lst = new;
		return ;
	}
	lst_move = *lst;
	while (lst_move->next)
		lst_move = lst_move->next;
	lst_move->next = new;
}
