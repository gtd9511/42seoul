/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 04:32:28 by sanghan           #+#    #+#             */
/*   Updated: 2022/11/16 19:58:35 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	cmd_rab(t_info *info, int flag)
{
	t_stack	*stack;
	int		elem;

	if (flag == RA || flag == RRRA)
	{
		stack = info->a;
		if (stack->size < 2)
			return ;
		if (flag == RA)
			write(1, "ra\n", 3);
	}
	else
	{
		stack = info->b;
		if (stack->size < 2)
			return ;
		if (flag == RB)
			write(1, "rb\n", 3);
	}
	elem = pop(stack);
	push_bot(stack, elem);
}

void	cmd_rr(t_info *info)
{
	cmd_rab(info, RRRA);
	cmd_rab(info, RRRB);
	write(1, "rr\n", 3);
}

void	cmd_rrab(t_info *info, int flag)
{
	t_stack	*stack;
	int		elem;

	if (flag == RRA || flag == RRRRA)
	{
		stack = info->a;
		if (stack->size < 2)
			return ;
		if (flag == RRA)
			write(1, "rra\n", 4);
	}
	else
	{
		stack = info->b;
		if (stack->size < 2)
			return ;
		if (flag == RRB)
			write(1, "rrb\n", 4);
	}
	elem = pop_bot(stack);
	push(stack, elem);
}

void	cmd_rrr(t_info *info)
{
	cmd_rrab(info, RRRRA);
	cmd_rrab(info, RRRRB);
	write(1, "rrr\n", 4);
}
