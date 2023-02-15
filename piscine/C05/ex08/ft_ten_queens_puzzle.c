/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:44:06 by sanghan           #+#    #+#             */
/*   Updated: 2022/01/22 15:20:54 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_ten_queens(int visited[10], int x, int y)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (y == visited [i] || i + visited[i] == x + y \
			  || i - visited[i] == x - y)
			return (0);
		i++;
	}
	return (1);
}

void	ft_backtracking(int visited[10], int *R, int pos)
{
	int	i;
	int	j;

	if (pos == 10)
	{
		*R += 1;
		j = -1;
		while (++j < 10)
			ft_putchar(visited[j] + '0');
		ft_putchar('\n');
	}
	else
	{
		i = -1;
		while (++i < 10)
		{
			if (ft_ten_queens(visited, pos, i))
			{
				visited[pos] = i;
				ft_backtracking(visited, R, pos + 1);
			}
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	i;
	int	r;
	int	visited[10];

	i = 0;
	while (i < 10)
	{
		visited[i] = -1;
		i++;
	}
	r = 0;
	ft_backtracking(visited, &r, 0);
	return (r);
}
