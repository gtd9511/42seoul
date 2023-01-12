/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 04:44:33 by sanghan           #+#    #+#             */
/*   Updated: 2022/11/03 15:25:31 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	key_w(t_map *info)
{
	char	elem;
	int		x;
	int		y;

	p_coord(info, &x, &y);
	elem = (info->map)[y - 1][x];
	if (elem == 'C')
		info->c_cnt++;
	if ((elem == 'E') && (info->all_c == info->c_cnt))
		clear_exit(info);
	else if (elem != '1' && elem != 'E')
	{
		(info->map)[y][x] = '0';
		(info->map)[y - 1][x] = 'P';
		info->step++;
		mlx_clear_window(info->mlx_ptr, info->win_ptr);
		draw_map(info);
	}
}

void	key_s(t_map *info)
{
	char	elem;
	int		x;
	int		y;

	p_coord(info, &x, &y);
	elem = (info->map)[y + 1][x];
	if (elem == 'C')
		info->c_cnt++;
	if ((elem == 'E') && (info->all_c == info->c_cnt))
		clear_exit(info);
	else if (elem != '1' && elem != 'E')
	{
		(info->map)[y][x] = '0';
		(info->map)[y + 1][x] = 'P';
		info->step++;
		mlx_clear_window(info->mlx_ptr, info->win_ptr);
		draw_map(info);
	}
}

void	key_a(t_map *info)
{
	char	elem;
	int		x;
	int		y;

	p_coord(info, &x, &y);
	elem = (info->map)[y][x - 1];
	if (elem == 'C')
		info->c_cnt++;
	if ((elem == 'E') && (info->all_c == info->c_cnt))
		clear_exit(info);
	else if (elem != '1' && elem != 'E')
	{
		(info->map)[y][x] = '0';
		(info->map)[y][x - 1] = 'P';
		info->step++;
		mlx_clear_window(info->mlx_ptr, info->win_ptr);
		draw_map(info);
	}
}

void	key_d(t_map *info)
{
	char	elem;
	int		x;
	int		y;

	p_coord(info, &x, &y);
	elem = (info->map)[y][x + 1];
	if (elem == 'C')
		info->c_cnt++;
	if ((elem == 'E') && (info->all_c == info->c_cnt))
		clear_exit(info);
	else if (elem != '1' && elem != 'E')
	{
		(info->map)[y][x] = '0';
		(info->map)[y][x + 1] = 'P';
		info->step++;
		mlx_clear_window(info->mlx_ptr, info->win_ptr);
		draw_map(info);
	}
}
