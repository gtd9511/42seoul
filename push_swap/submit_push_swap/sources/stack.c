/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 04:00:45 by sanghan           #+#    #+#             */
/*   Updated: 2022/11/16 05:56:42 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	new_stack(t_stack *stack)
{
	stack->top = (t_node *)malloc(sizeof(t_node));
	if (!stack->top)
		error_exit(1);
	stack->bot = (t_node *)malloc(sizeof(t_node));
	if (!stack->bot)
		error_exit(1);
	stack->top->next = NULL;
	stack->top->data = -1;
	stack->top->prev = stack->bot;
	stack->bot->next = stack->top;
	stack->bot->data = -1;
	stack->bot->prev = NULL;
	stack->size = 0;
}

int	pop(t_stack *stack)
{
	int		elem;
	t_node	*temp;

	if (stack->size > 0)
	{
		elem = stack->top->prev->data;
		temp = stack->top->prev;
		stack->top->prev = temp->prev;
		temp->prev->next = stack->top;
		free(temp);
		temp = NULL;
		stack->size--;
		return (elem);
	}
	else
		write(2, "empty stack\n", 12);
	return (-1);
}

int	pop_bot(t_stack *stack)
{
	int		elem;
	t_node	*temp;

	if (stack->top->prev != stack->bot)
	{
		elem = stack->bot->next->data;
		temp = stack->bot->next;
		stack->bot->next = temp->next;
		temp->next->prev = stack->bot;
		free(temp);
		temp = NULL;
		stack->size--;
		return (elem);
	}
	else
		write(2, "empty stack\n", 12);
	return (-1);
}

void	push(t_stack *stack, int elem)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		error_exit(1);
	new->data = elem;
	new->prev = stack->top->prev;
	stack->top->prev->next = new;
	new->next = stack->top;
	stack->top->prev = new;
	stack->size++;
}

void	push_bot(t_stack *stack, int elem)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		error_exit(1);
	new->data = elem;
	new->next = stack->bot->next;
	stack->bot->next->prev = new;
	new->prev = stack->bot;
	stack->bot->next = new;
	stack->size++;
}
