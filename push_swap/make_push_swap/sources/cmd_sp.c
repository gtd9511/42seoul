/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_sp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 04:32:33 by sanghan           #+#    #+#             */
/*   Updated: 2022/11/16 16:46:17 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	cmd_sab(t_info *info, int flag)
{
	t_stack	*stack;
	int		elem1;
	int		elem2;

	if (flag == SA || flag == SSSA)
	{
		stack = info->a;
		if (flag == SA)
			write(1, "sa\n", 3);
	}
	else
	{
		stack = info->b;
		if (flag == SB)
			write(1, "sb\n", 3);
	}

	if (stack->size < 2)
		return ;
	elem1 = pop(stack);
	elem2 = pop(stack);
	push(stack, elem1);
	push(stack, elem2);
}

void	cmd_ss(t_info *info)
{
	cmd_sab(info, SSSA);
	cmd_sab(info, SSSB);
	write(1, "ss\n", 3);
}

void	cmd_pab(t_info *info, int flag)
{
	t_stack	*stack;
	int		elem;

	if (flag == PA)
	{
		stack = info->a;
		write(1, "pa\n", 3);
	}
	else
	{
		stack = info->b;
		write(1, "pb\n", 3);
	}

	if (is_empty(stack))
		return ;
	elem = pop(stack);
	push(stack, elem);
}
