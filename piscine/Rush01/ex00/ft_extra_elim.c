/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_elim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 12:08:01 by tayeo             #+#    #+#             */
/*   Updated: 2022/01/16 20:22:08 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdbool.h>
void	next(bool axis, int *i, int *j);

void	set_index(int *i, int *j, bool axis, char n_box)
{
	if (axis == 1)
		*j = n_box;
	else
		*i = n_box;
}

void	elim22_ex1(char board[4][4][4], bool axis, char n_box)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	set_index(&i, &j, axis, n_box);
	if (board[i][j][2] == '0')
		count++;
	next(axis, &i, &j);
	if (board[i][j][1] == '0')
		count++;
	next(axis, &i, &j);
	if (board[i][j][3] == '0')
		count++;
	next(axis, &i, &j);
	if (count > 0)
		board[i][j][0] = '0';
}

void	elim22_ex2(char board[4][4][4], bool axis, char n_box)
{
	int	i;
	int	j;
	int	count;
	int	temp[2];

	i = 0;
	j = 0;
	count = 0;
	set_index(&i, &j, axis, n_box);
	temp[0] = i;
	temp[1] = j;
	next(axis, &i, &j);
	if (board[i][j][3] == '0')
		count++;
	next(axis, &i, &j);
	if (board[i][j][1] == '0')
		count++;
	next(axis, &i, &j);
	if (board[i][j][2] == '0')
		count++;
	i = temp[0];
	j = temp[1];
	if (count > 0)
		board[i][j][0] = '0';
}
