/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:24:51 by sanghan           #+#    #+#             */
/*   Updated: 2022/11/16 17:18:46 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_a_idx(int num, t_info *info)
{
	int	elem;

	if (num < get_min_stack(info->a))
		elem = set_min(info);
	else if (num > get_max_stack(info->a))
		elem = set_max(info);
	else
		elem = set_mid(num, info);
	return (elem);
}

int	set_min(t_info *info)
{
	int		elem;
	int		target;
	int		temp;
	t_node	*idx;

	elem = 0;
	target = 0;
	target = get_min_stack(info->a);
	idx = info->a->top->prev;
	while (idx != info->a->bot)
	{
		temp = idx->data;
		if (temp == target)
			break ;
		idx = idx->prev;
		elem++;
	}
	if (elem >= (info->a->size + 1) / 2)
		elem = (info->a->size - elem) * -1;
	return (elem);
}

int	set_mid(int num, t_info *info)
{
	t_node	*idx;
	int		elem;

	elem = 1;
	idx = info->a->top->prev;
	while (idx->prev != info->a->bot)
	{
		if (num > idx->data && num < idx->prev->data)
			break ;
		elem++;
		idx = idx->prev;
	}
	if (elem >= (info->a->size + 1) / 2)
		elem = (info->a->size - elem) * -1;
	return (elem);
}

int	set_max(t_info *info)
{
	int		elem;
	int		target;
	int		temp;
	t_node	*idx;

	elem = 0;
	target = 0;
	target = get_max_stack(info->a);
	idx = info->a->top->prev;
	while (idx != info->a->bot)
	{
		temp = idx->data;
		if (temp == target)
			break ;
		idx = idx->prev;
		elem++;
	}
	elem++;
	if (elem >= (info->a->size + 1) / 2)
		elem = (info->a->size - elem) * -1;
	return (elem);
}

void	set_pivot_divide(t_info *info)
{
	int	idx;
	int	piv1;
	int	piv2;

	idx = info->a->size / 3;
	piv1 = info->array[idx];
	idx = info->a->size * 2 / 3;
	piv2 = info->array[idx];
	idx = info->a->size;
	while (idx)
	{
		divide_triple(info, piv1, piv2);
		idx--;
	}
}
