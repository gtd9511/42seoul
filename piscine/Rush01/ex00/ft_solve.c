/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:18:24 by tayeo             #+#    #+#             */
/*   Updated: 2022/01/16 20:22:14 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdbool.h>
void	elim12(char board[4][4][4], bool axis, char n_box);
void	elim13(char board[4][4][4], bool axis, char n_box);
void	elim14(char board[4][4][4], bool axis, char n_box);
void	elim22(char board[4][4][4], bool axis, char n_box);
void	elim23(char board[4][4][4], bool axis, char n_box);
void	elim21(char board[4][4][4], bool axis, char n_box);
void	elim31(char board[4][4][4], bool axis, char n_box);
void	elim41(char board[4][4][4], bool axis, char n_box);
void	elim32(char board[4][4][4], bool axis, char n_box);
void	elim22_ex1(char board[4][4][4], bool axis, char n_box);
void	elim22_ex2(char board[4][4][4], bool axis, char n_box);
int		find_unique(char board[4]);
int		check_unique(char board[4]);

void	ft_remove(int value, char board[4][4][4], int i, int j)
{
	int	min;
	int	max;
	int	temp;

	min = 0;
	max = 3;
	temp = i;
	while (min < i)
		board[min++][j][value - 1] = '0';
	min = 0;
	while (min < j)
		board[i][min++][value - 1] = '0';
	while (i < max)
		board[++i][j][value - 1] = '0';
	i = temp;
	while (j < max)
		board[i][++j][value - 1] = '0';
}

void	rule_check(char board[4][4][4])
{
	int	i;
	int	j;
	int	check;
	int	cnt;

	cnt = 0;
	while (cnt < 16)
	{
		i = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				check = check_unique(board[i][j]);
				if (check == 1)
					ft_remove(find_unique(board[i][j]), board, i, j);
				j++;
			}
			i++;
		}
		cnt++;
	}
}

int	ft_selecter(char input1, char input2, int i, char board[4][4][4])
{
	if (input1 == '1' && input2 == '2')
		elim12(board, i < 4, i % 8);
	else if (input1 == '1' && input2 == '3')
		elim13(board, i < 4, i % 8);
	else if (input1 == '1' && input2 == '4')
		elim14(board, i < 4, i % 8);
	else if (input1 == '2' && input2 == '2')
		elim22(board, i < 4, i % 8);
	else if (input1 == '2' && input2 == '3')
		elim23(board, i < 4, i % 8);
	else if (input1 == '2' && input2 == '1')
		elim21(board, i < 4, i % 8);
	else if (input1 == '3' && input2 == '1')
		elim31(board, i < 4, i % 8);
	else if (input1 == '4' && input2 == '1')
		elim41(board, i < 4, i % 8);
	else if (input1 == '3' && input2 == '2')
		elim32(board, i < 4, i % 8);
	else
		return (-1);
	return (1);
}

void	ft_selecter_ex(char input1, char input2, int i, char board[4][4][4])
{
	if (input1 == '2' && input2 == '2')
	{
		elim22_ex1(board, i < 4, i % 8);
		elim22_ex2(board, i < 4, i % 8);
	}
}

int	eliminater(char *input, char board[4][4][4])
{
	int	i;
	int	pair_check;

	i = 0;
	while (i < 12)
	{
		pair_check = ft_selecter(input[i], input[i + 4], i, board);
		if (pair_check == -1)
			return (0);
		i += 1 + (bool)(i == 3) * 4;
	}
	rule_check(board);
	i = 0;
	while (i < 12)
	{
		ft_selecter_ex(input[i], input[i + 4], i, board);
		i += 1 + (bool)(i == 3) * 4;
	}
	rule_check(board);
	return (1);
}
