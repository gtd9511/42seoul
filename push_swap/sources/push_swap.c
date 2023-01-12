/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:43:21 by sanghan           #+#    #+#             */
/*   Updated: 2022/11/17 05:30:24 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	error_exit(int type)
{
	if (type >= 1)
		write(2, "Error\n", 6);
	exit(1);
	return (-1);
}

int	make_pos(int a, int b, int a_idx, int b_idx)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a_idx < 0)
		a_idx *= -1;
	if (b_idx < 0)
		b_idx *= -1;
	if (a + b > a_idx + b_idx)
		return (1);
	else
		return (0);
}

void	check_dup(t_info *info, int arr_size)
{
	int	*array;
	int	i;
	int	j;

	array = info->array;
	i = 0;
	j = 0;
	while (i < arr_size)
	{
		j = i + 1;
		while (j < arr_size)
		{
			if (array[i] == array[j])
			{
				free_stack(info->a);
				free_stack(info->b);
				free(info->array);
				error_exit(1);
			}
			j++;
		}
		i++;
	}
}

int	*sort_array(int *arr, int arr_size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < arr_size)
	{
		j = i;
		while (++j < arr_size)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			if (arr[i] == arr[j])
				error_exit(1);
		}
		i++;
	}
	return (arr);
}

int	main(int argc, char **argv)
{
	int		*arr;
	int		arr_size;
	t_stack	a;
	t_stack	b;
	t_info	info;

	if (argc < 2)
		error_exit(-1);
	arr_size = 0;
	new_stack(&a);
	new_stack(&b);
	info.a = &a;
	info.b = &b;
	arr_size = get_input_size(argc, argv);
	arr = make_array(argc, argv, arr_size);
	info.array = arr;
	arr_to_stack(&info, arr, arr_size);
	check_dup(&info, arr_size);
	check_sort(arr, arr_size, 0);
	arr = sort_array(arr, arr_size);
	sort_elem(&info, arr);
	free(info.array);
	free_stack(info.a);
	free_stack(info.b);
}
