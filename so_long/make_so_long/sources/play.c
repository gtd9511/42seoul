/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 04:44:35 by sanghan           #+#    #+#             */
/*   Updated: 2022/11/03 19:42:09 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	p_coord(t_map *info, int *x, int *y)
{
	int	idx_x;
	int	idx_y;

	idx_y = 0;
	while (idx_y < info->lines)
	{
		idx_x = 0;
		while (idx_x < info->len)
		{
			if ((info->map)[idx_y][idx_x] == 'P')
			{
				*x = idx_x;
				*y = idx_y;
				return ;
			}
			idx_x++;
		}
		idx_y++;
	}
}

void	clear_exit(t_map *info)
{
	free_map(info);
	write(1, "Clear!!\n", 8);
	mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	exit(0);
}

int	exit_game(t_map *info)
{
	free_map(info);
	mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	exit(0);
}

int	press_key(int keydown, t_map *info)
{
	if (keydown == ESC_KEY)
		exit_game(info);
	else if (keydown == W_KEY)
		key_w(info);
	else if (keydown == S_KEY)
		key_s(info);
	else if (keydown == A_KEY)
		key_a(info);
	else if (keydown == D_KEY)
		key_d(info);
	if (info->step > 1)
		printf("%d steps\n", info->step);
	else
		printf("%d step\n", info->step);
	return (0);
}
