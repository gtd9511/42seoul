/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:30:18 by tayeo             #+#    #+#             */
/*   Updated: 2022/01/16 20:22:01 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
int	find_unique(char board[4])
{
	int	i;

	i = 0;
	while (board[i] == '0')
		i++;
	return ((int)board[i] - '0');
}

int	check_unique(char board[4])
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < 4)
	{
		if (board[i] != '0')
			count++;
		i++;
	}
	return (count);
}

int	is_n(char *argv)
{
	if (argv[0] > '0' && argv[0] < '5')
		return (1);
	else
		return (0);
}

void	put_space(int j)
{
	if (j < 3)
		write(1, " ", 1);
}
