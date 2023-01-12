/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:14:24 by sanghan           #+#    #+#             */
/*   Updated: 2022/11/16 21:41:32 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_atoil(const char *str, int i)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
		if (str[i] == '\0')
			error_exit(1);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	result *= (long)sign;
	if (str[i] != '\0' || result > 2147483647 || result < -2147483648)
		error_exit(1);
	return ((int)(result));
}

void	set_str_array(int *array, int *arr_idx, char **str)
{
	int	temp;
	int	idx;

	idx = 0;
	while (str[idx])
	{
		temp = ft_atoil(str[idx], 0);
		array[*arr_idx] = temp;
		(*arr_idx) += 1;
		idx++;
	}
}

int	*make_array(int argc, char **argv, int size)
{
	int		argc_idx;
	int		arr_idx;
	int		*array;
	char	**split_str;

	argc_idx = 1;
	arr_idx = 0;
	array = (int *)malloc(sizeof(int) * (size));
	if (!array)
		error_exit(1);
	while (argc_idx < argc)
	{
		split_str = ft_split(argv[argc_idx], ' ');
		set_str_array(array, &arr_idx, split_str);
		free_split(split_str);
		argc_idx++;
	}
	return (array);
}
