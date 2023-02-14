/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elim2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:58:31 by tayeo             #+#    #+#             */
/*   Updated: 2022/01/16 20:21:55 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdbool.h>
void	next(bool axis, int *i, int *j);

void	elim22(char	board[4][4][4], bool axis, char n_box)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (axis == 1)
		j = n_box;
	else
		i = n_box;
	board[i][j][3] = '0';
	next(axis, &i, &j);
	board[i][j][2] = '0';
	next(axis, &i, &j);
	board[i][j][2] = '0';
	next(axis, &i, &j);
	board[i][j][3] = '0';
}

void	elim21(char	board[4][4][4], bool axis, char n_box)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (axis == 1)
		j = n_box;
	else
		i = n_box;
	board[i][j][0] = '0';
	board[i][j][1] = '0';
	board[i][j][3] = '0';
	next(axis, &i, &j);
	board[i][j][2] = '0';
	board[i][j][3] = '0';
	next(axis, &i, &j);
	board[i][j][2] = '0';
	board[i][j][3] = '0';
	next(axis, &i, &j);
	board[i][j][0] = '0';
	board[i][j][1] = '0';
	board[i][j][2] = '0';
}

void	elim31(char	board[4][4][4], bool axis, char n_box)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (axis == 1)
		j = n_box;
	else
		i = n_box;
	board[i][j][2] = '0';
	board[i][j][3] = '0';
	next(axis, &i, &j);
	board[i][j][1] = '0';
	board[i][j][3] = '0';
	next(axis, &i, &j);
	board[i][j][3] = '0';
	next(axis, &i, &j);
	board[i][j][0] = '0';
	board[i][j][1] = '0';
	board[i][j][2] = '0';
}

void	elim41(char	board[4][4][4], bool axis, char n_box)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (axis == 1)
		j = n_box;
	else
		i = n_box;
	board[i][j][1] = '0';
	board[i][j][2] = '0';
	board[i][j][3] = '0';
	next(axis, &i, &j);
	board[i][j][0] = '0';
	board[i][j][2] = '0';
	board[i][j][3] = '0';
	next(axis, &i, &j);
	board[i][j][0] = '0';
	board[i][j][1] = '0';
	board[i][j][3] = '0';
	next(axis, &i, &j);
	board[i][j][0] = '0';
	board[i][j][1] = '0';
	board[i][j][2] = '0';
}

void	elim32(char	board[4][4][4], bool axis, char n_box)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (axis == 1)
		j = n_box;
	else
		i = n_box;
	board[i][j][2] = '0';
	board[i][j][3] = '0';
	next(axis, &i, &j);
	board[i][j][0] = '0';
	board[i][j][3] = '0';
	next(axis, &i, &j);
	board[i][j][0] = '0';
	board[i][j][1] = '0';
	board[i][j][2] = '0';
	next(axis, &i, &j);
	board[i][j][3] = '0';
}
