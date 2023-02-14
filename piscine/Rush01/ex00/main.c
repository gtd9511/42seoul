/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:25:33 by tayeo             #+#    #+#             */
/*   Updated: 2022/01/16 20:22:24 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
int		find_unique(char board[4]);
int		check_unique(char board[4]);
int		is_n(char	*argv);
void	put_space(int j);
void	eliminater(char *input, char board[4][4][4]);

int	input_checker(char *av, char *input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i] != 0)
	{
		if (!((i == 0 && is_n(av + i)) || (is_n(av + i - 1) && av[i] == 32) || \
		(av[i - 1] == 32 && is_n(av + i))))
			return (0);
		if (((i == 0 && is_n(av + i)) || (av[i - 1] == 32 && is_n(av + i))) && \
				j < 16)
		{
			input[j] = av[i];
			j++;
		}
		i++;
	}
	if (i != 31)
		return (0);
	return (1);
}

void	init_board(char board[4][4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			board[i][j][0] = '1';
			board[i][j][1] = '2';
			board[i][j][2] = '3';
			board[i][j][3] = '4';
			j++;
		}
		i++;
	}
}

int	error_board(char board[4][4][4])
{
	int	i;
	int	j;
	int	u;

	i = 0;
	j = 0;
	u = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			u = check_unique(board[i][j]);
			if (u != 1)
			{	
				return (0);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

void	show_board(char	board[4][4][4])
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				if (board[i][j][k] != '0')
				{
					write(1, &board[i][j][k], 1);
					put_space(j);
				}
				k++;
			}	
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	input[16];
	char	board[4][4][4];
	int		e;

	e = 0;
	if (argc == 2 && input_checker(argv[1], input))
	{
		init_board(board);
		eliminater(input, board);
		e = error_board(board);
		if (e == 1)
			show_board(board);
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
}
