/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:38:17 by kyoulee           #+#    #+#             */
/*   Updated: 2022/03/25 19:24:11 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
	{
		if (*lst == NULL)
			*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}
