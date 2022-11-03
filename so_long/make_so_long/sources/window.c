/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 04:44:38 by sanghan           #+#    #+#             */
/*   Updated: 2022/11/03 18:08:57 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_window(t_map *info)
{
	int	width;
	int	height;

	info->win_ptr = mlx_new_window(info->mlx_ptr, LEN * info->len, \
	LEN * info->lines, "so_long");
	width = LEN;
	height = LEN;
	get_ptrs(info, &width, &height);
	mlx_hook(info->win_ptr, X_EVENT_KEY_RELEASE, 0, &press_key, info);
	mlx_hook(info->win_ptr, X_EVENT_KEY_EXIT, 0, &exit_game, info);
	mlx_loop(info->mlx_ptr);
}

void	get_ptrs(t_map *info, int *width, int *height)
{
	info->l_ptr = \
	mlx_xpm_file_to_image(info->mlx_ptr, "./images/load.xpm", width, height);
	info->w_ptr = \
	mlx_xpm_file_to_image(info->mlx_ptr, "./images/wall.xpm", width, height);
	info->p_ptr = \
	mlx_xpm_file_to_image(info->mlx_ptr, "./images/mario.xpm", width, height);
	info->e_ptr = \
	mlx_xpm_file_to_image(info->mlx_ptr, "./images/pip.xpm", width, height);
	info->c_ptr = \
	mlx_xpm_file_to_image(info->mlx_ptr, "./images/coin1.xpm", width, height);
	draw_map(info);
}

void	draw_map(t_map *info)
{
	char	**map;
	int		x;
	int		y;

	map = info->map;
	x = 0;
	while (*map)
	{
		y = 0;
		while (y < info->len)
		{
			draw_image(info, (*map)[y], y * LEN, x * LEN);
			y++;
		}
		x++;
		map++;
	}
}

void	draw_image(t_map *info, char elem, int x, int y)
{
	draw_image_window(info, info->l_ptr, x, y);
	draw_image_window(info, info->w_ptr, x, y);
	if (elem == '1')
	{
		draw_image_window(info, info->l_ptr, x, y);
		draw_image_window(info, info->w_ptr, x, y);
	}
	else if (elem == '0')
		draw_image_window(info, info->l_ptr, x, y);
	else if (elem == 'P')
	{
		draw_image_window(info, info->l_ptr, x, y);
		draw_image_window(info, info->p_ptr, x, y);
	}
	else if (elem == 'C')
	{
		draw_image_window(info, info->l_ptr, x, y);
		draw_image_window(info, info->c_ptr, x, y);
	}
	else if (elem == 'E')
	{
		draw_image_window(info, info->l_ptr, x, y);
		draw_image_window(info, info->e_ptr, x, y);
	}
}

void	draw_image_window(t_map *info, void *draw_ptr, int x, int y)
{
	void	*m_ptr;
	void	*w_ptr;

	m_ptr = info->mlx_ptr;
	w_ptr = info->win_ptr;
	mlx_put_image_to_window(m_ptr, w_ptr, draw_ptr, x, y);
}
