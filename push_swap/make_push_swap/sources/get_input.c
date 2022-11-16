/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 04:23:01 by sanghan           #+#    #+#             */
/*   Updated: 2022/11/16 16:05:34 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isspace(char c)
{
	if (c == '\n' || c == '\v' || c == '\t' \
	|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	split_size(char **parsed_str)
{
	int	idx;

	idx = 0;
	while (parsed_str[idx])
		idx++;
	return (idx);
}

void	free_split(char **parsed_str)
{
	int	idx;

	idx = 0;
	while (parsed_str[idx])
	{
		free(parsed_str[idx]);
		idx++;
	}
	free(parsed_str);
}

int	get_input_size(int argc, char **argv)
{
	int		idx;
	int		size;
	int		elem_cnt;
	char	**split_str;

	idx = 1;
	size = 0;
	while (idx < argc)
	{
		elem_cnt = 0;
		while (argv[idx][elem_cnt])
		{
			if (!ft_isspace(argv[idx][elem_cnt]))
				break ;
				elem_cnt++;
		}
		if (argv[idx][elem_cnt] == '\0')
			error_exit(1);
		split_str = ft_split(argv[idx], ' ');
		size += split_size(split_str);
		free_split(split_str);
		idx++;
	}
	return (size);
}

void	arr_to_stack(t_info *info, int *arr, int size)
{
	int	idx;

	idx = size - 1;
	while (idx--)
		push(info->a, arr[idx]);
}
