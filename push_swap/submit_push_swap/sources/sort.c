/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:29:49 by sanghan           #+#    #+#             */
/*   Updated: 2022/11/17 05:25:12 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_sort(int *array, int size, int idx)
{
	int	j;
	int	checker;
	int	tmp;

	checker = 0;
	while (idx < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				checker++;
			}
				j++;
		}
		idx++;
	}
	if (checker == 0)
		error_exit(-1);
}

void	sort_all(t_info *info, int *sorted_array)
{
	int	a;
	int	b;

	set_pivot_divide(info, sorted_array);
	while (info->a->size > 3)
		cmd_pab(info, PB);
	if (info->a->size == 2)
	{
		if (info->a->top->prev->data > info->a->bot->next->data)
			cmd_sab(info, SA);
	}
	else
		sort_triple(info);
	while (info->b->size > 0)
	{
		a = 0;
		b = 0;
		get_min_rtcnt(info, &a, &b);
		rotate_many(info, &a, &b);
		rotate_one(info, a, 1);
		rotate_one(info, b, 0);
		cmd_pab(info, PA);
	}
	last_sort(info);
}

void	sort_elem(t_info *info, int *sorted_array)
{
	if (info->a->size == 2)
	{
		if (info->a->top->prev->data > info->a->bot->next->data)
			cmd_sab(info, SA);
	}
	else if (info->a->size == 3)
		sort_triple(info);
	else
		sort_all(info, sorted_array);
}

void	last_sort(t_info *info)
{
	int	min_idx;

	min_idx = set_min(info);
	while (min_idx)
	{
		if (min_idx > 0)
		{
			cmd_rab(info, RA);
			min_idx--;
		}
		else
		{
			cmd_rrab(info, RRA);
			min_idx++;
		}
	}
}

void	sort_triple(t_info *info)
{
	int	top;
	int	bot;
	int	mid;

	top = info->a->top->prev->data;
	bot = info->a->bot->next->data;
	mid = info->a->bot->next->next->data;
	if (top < mid && mid > bot && top < bot)
	{
		cmd_sab(info, SA);
		cmd_rab(info, RA);
	}
	else if (top > mid && mid < bot && top < bot)
		cmd_sab(info, SA);
	else if (top < mid && mid > bot && top > bot)
		cmd_rrab(info, RRA);
	else if (top > mid && bot > mid && top > bot)
		cmd_rab(info, RA);
	else if (top > mid && mid > bot && top > bot)
	{
		cmd_sab(info, SA);
		cmd_rrab(info, RRA);
	}
}
