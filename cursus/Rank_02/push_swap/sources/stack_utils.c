/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:28:30 by sanghan           #+#    #+#             */
/*   Updated: 2022/11/16 15:29:23 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_empty(t_stack *stack)
{
	return (stack->size == 0);
}

int	get_min_stack(t_stack *stack)
{
	t_node	*node;
	int		elem;

	node = stack->bot->next;
	elem = node->data;
	while (node != stack->top)
	{
		if (elem > node->data)
			elem = node->data;
		node = node->next;
	}
	return (elem);
}

int	get_max_stack(t_stack *stack)
{
	t_node	*node;
	int		elem;

	node = stack->bot->next;
	elem = node->data;
	while (node != stack->top)
	{
		if (elem < node->data)
			elem = node->data;
		node = node->next;
	}
	return (elem);
}

void	free_stack(t_stack *stack)
{
	int		idx;
	t_node	*n_idx;
	t_node	*tmp;

	idx = 0;
	n_idx = stack->bot->next;
	while (idx < stack->size)
	{
		tmp = n_idx;
		free(tmp);
		n_idx = n_idx->next;
		idx++;
	}
	free(stack->top);
	free(stack->bot);
}
