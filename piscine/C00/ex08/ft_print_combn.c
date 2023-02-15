/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:31:48 by sanghan           #+#    #+#             */
/*   Updated: 2022/01/11 14:46:54 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
void	ft_print_com(bool visited[], int count, int a)
{
	a = 0;
	while (a < 10)
	{
		if (!visited[a])
		{
			a++;
		}
		else
			break ;
	}
	if (count != 10 - a)
	{
		write (1, ", ", 2);
	}
}

void	ft_print_num(bool visited[])
{
	int		i;
	int		count;
	char	c;

	i = 0;
	count = 0;
	while (i < 10)
	{
		if (visited[i])
		{
			c = '0' + i;
			write(1, &c, 1);
			count++;
		}
		i++;
	}
	ft_print_com(visited, count, 0);
}

void	backtracking(char nums[], bool visited[], int R, int start)
{
	int	i;

	if (R == 0)
	{
		ft_print_num(visited);
	}
	else
	{
		i = start;
		while (i < 10)
		{
			visited[i] = true;
			backtracking(nums, visited, R - 1, i + 1);
			visited[i] = false;
			i++;
		}
	}
}

void	ft_print_combn(int n)
{
	int		r;
	int		i;
	char	nums[10];
	bool	visited[10];

	r = n;
	i = 0;
	while (i < 10)
	{
		nums[i] = '0' + i;
		i++;
	}
	i = 0;
	while (i < 10)
	{
		visited[i] = false;
		i++;
	}
	backtracking (nums, visited, r, 0);
}
