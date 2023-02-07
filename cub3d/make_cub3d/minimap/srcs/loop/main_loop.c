/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:43:27 by doykim            #+#    #+#             */
/*   Updated: 2023/02/05 17:27:25 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define TILE_SIZE 32
#define WILE_SIZE 1920
#define HILE_SIZE 1080

void    draw_square(t_game *game, int x, int y, int color)
{
	int dx;
	int dy;

	dy = 0;
	while (dy < TILE_SIZE)
	{
		dx = 0;
		while (dx < TILE_SIZE)
		{
			game->img->data[WILE_SIZE * (y + dy) + (x + dx)] = color;
			dx++;
		}
		dy++;
	}
}

void	draw_squares(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == '1')
			{
				printf("here is 1  x : %d   y : %d \n", x, y);
				draw_square(game, TILE_SIZE * x, TILE_SIZE * y, 0x0000FF);
			}
			else
			{
				printf("here is not 1  x : %d   y : %d \n", x, y);
				draw_square(game, TILE_SIZE * x, TILE_SIZE * y, 0xFFFFFF);
			}
			x++;
		}
		y++;
	}
}

void	draw_line(t_game *game, double x1, double y1, double x2, double y2)
{
	double	deltaX;
	double	deltaY;
	double	step;

	deltaX = x2 - x1;
	deltaY = y2 - y1;
	step = (fabs(deltaX) > fabs(deltaY)) ? fabs(deltaX) : fabs(deltaY);
	deltaX /= step;
	deltaY /= step;
	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
	{
		game->img->data[(int)floor(y1) * WILE_SIZE + (int)floor(x1)] = 0xC0C0C0;
		x1 += deltaX;
		y1 += deltaY;
	}
}

void	draw_lines(t_game *game)
{
	int i;

	i = 0;
	while (i <= game->map_height)
	{
		draw_line(game, 0, TILE_SIZE * i, WILE_SIZE, TILE_SIZE * i);
		i++;
	}
	i = 0;
	while (i <= game->map_width)
	{
		draw_line(game, TILE_SIZE * i, 0, TILE_SIZE * i, HILE_SIZE);
		i++;
	}
}

void	ceilfloor(t_game *game, int flag)
{
	int	i;
	int	j;

	i = 0;
	while (i < 1920)
	{
		if (flag == 0)
		{
			j = 0;
			while (j < 540)
			{
				mlx_pixel_put(game->mlx, game->win, i, j, 0x000000FF);
				j++;
			}
		}
		else
		{
			j = 540;
			while (j < 1080)
			{
				mlx_pixel_put(game->mlx, game->win, i, j, 0x00FF0000);
				j++;
			}
		}
		i++;
	}
}
int	main_loop(t_game *game)
{
	int	cf_flag;

	cf_flag = 0;
	game->img->data = (int *)mlx_get_data_addr(game->img->img, &(game->img->bpp), \
		&(game->img->line_len), &(game->img->endian));
	ceilfloor(game, cf_flag);
	cf_flag = 1;
	ceilfloor(game, cf_flag);
	mlx_put_image_to_window(game->mlx, game->win, game->ceil, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->floor, 0, 540);
//	draw_squares(game);
//	draw_lines(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
	return (0);
}