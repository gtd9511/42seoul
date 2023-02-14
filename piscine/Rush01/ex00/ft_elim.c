/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:39:51 by sanghan           #+#    #+#             */
/*   Updated: 2022/01/16 20:21:50 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
void	next(bool axis, int *i, int *j)
{
	if (axis == 1)
		*i = *i + 1;
	else
		*j = *j + 1;
}

void	elim12(char	board[4][4][4], bool axis, char n_box)
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
	board[i][j][2] = '0';
	next(axis, &i, &j);
	board[i][j][2] = '0';
	board[i][j][3] = '0';
	next(axis, &i, &j);
	board[i][j][2] = '0';
	board[i][j][3] = '0';
	next(axis, &i, &j);
	board[i][j][0] = '0';
	board[i][j][1] = '0';
	board[i][j][3] = '0';
}

void	elim13(char	board[4][4][4], bool axis, char n_box)
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
	board[i][j][2] = '0';
	next(axis, &i, &j);
	board[i][j][3] = '0';
	next(axis, &i, &j);
	board[i][j][1] = '0';
	board[i][j][3] = '0';
	next(axis, &i, &j);
	board[i][j][2] = '0';
	board[i][j][3] = '0';
}

void	elim14(char	board[4][4][4], bool axis, char n_box)
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
	board[i][j][2] = '0';
	next(axis, &i, &j);
	board[i][j][0] = '0';
	board[i][j][1] = '0';
	board[i][j][3] = '0';
	next(axis, &i, &j);
	board[i][j][0] = '0';
	board[i][j][2] = '0';
	board[i][j][3] = '0';
	next(axis, &i, &j);
	board[i][j][1] = '0';
	board[i][j][2] = '0';
	board[i][j][3] = '0';
}

void	elim23(char	board[4][4][4], bool axis, char n_box)
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
	board[i][j][0] = '0';
	board[i][j][1] = '0';
	board[i][j][2] = '0';
	next(axis, &i, &j);
	board[i][j][0] = '0';
	board[i][j][3] = '0';
	next(axis, &i, &j);
	board[i][j][2] = '0';
	board[i][j][3] = '0';
}
