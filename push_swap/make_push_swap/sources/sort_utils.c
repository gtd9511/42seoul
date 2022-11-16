/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 06:41:05 by sanghan           #+#    #+#             */
/*   Updated: 2022/11/16 15:52:47 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_many(t_info *info, int *a, int *b)
{
	while (*a && *b && (*a > 0 && *b > 0))
	{
		cmd_rr(info);
		*a -= 1;
		*b -= 1;
	}
	while (*a && *b && (*a < 0 && *b < 0))
	{
		cmd_rrr(info);
		*a += 1;
		*b += 1;
	}
}

void	rotate_one(t_info *info, int idx, int flag)
{
	while (idx > 0)
	{
		if (flag)
			cmd_rab(info, RA);
		else
			cmd_rab(info, RB);
		idx--;
	}
	while (idx < 0)
	{
		if (flag)
			cmd_rrab(info, RRA);
		else
			cmd_rrab(info, RRB);
		idx++;
	}
}

void	divide_triple(t_info *info, int piv1, int piv2)
{
	if (info->a->top->prev->data < piv1)
	{
		cmd_pab(info, PB);
		cmd_rab(info, RA);
	}
	else if (info->a->top->prev->data < piv2)
		cmd_pab(info, PB);
	else
		cmd_rab(info, RA);
}

void	get_min_rtcnt(t_info *info, int *a, int *b)
{
	int		a_idx;
	int		b_idx;
	int		idx;
	t_node	*b_node;
	int		num;

	idx = 0;
	b_node = info->b->top->prev;
	while (idx < info->b->size)
	{
		num = b_node->data;
		a_idx = get_a_idx(num, info);
		if (idx >= (info->b->size + 1) / 2)
			b_idx = (info->b->size - idx) * -1;
		else
			b_idx = idx;
		if (idx == 0 || make_pos(*a, *b, a_idx, b_idx))
		{
			*a = a_idx;
			*b = b_idx;
		}
		b_node = b_node->prev;
		idx++;
	}
}
