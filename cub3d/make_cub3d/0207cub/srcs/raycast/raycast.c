/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:43:27 by doykim            #+#    #+#             */
/*   Updated: 2023/02/07 20:36:12 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_game *game)
{
	t_ray	ray;
	int		x;

	while (x < WIDTH)
	{
		ray.cameraX = (2 * x / (double)WIDTH) - 1;
		ray.ray_dir_x = game->player.x + game->plane_x * ray.cameraX;
		ray.ray_dir_y = game->player.y + game->plane_y * ray.cameraX;
		ray.mapX = (int)game->player.x;
		ray.mapY = (int)game->player.y;
		if (ray.ray_dir_x != 0)
			ray.deltaDistX = fabs(1 / ray.ray_dir_x);
		if (ray.ray_dir_x != 0)
			ray.deltaDistY = fabs(1 / ray.ray_dir_y);
		ray.hit = 0;

		if (ray.ray_dir_x < 0)
		{
			ray.stepX = -1;
			ray.sideDistX = (game->player.x - ray.mapX) * ray.deltaDistX;
		}
		else
		{
			ray.stepX = 1;
			ray.sideDistX = (ray.mapX + 1.0 - game->player.x) * ray.deltaDistX;
		}
		if (ray.ray_dir_y < 0)
		{
			ray.stepY = -1;
			ray.sideDistY = (game->player.y - ray.mapX) * ray.deltaDistY;
		}
		else{
			ray.stepY = 1;
			ray.sideDistY = (ray.mapY + 1.0 - game->player.y) * ray.deltaDistY;
		}
	}

	ray.mapX = game->player.x;
	ray.mapY = game->player.y;
	while (ray.hit == 0)
	{
		if (ray.sideDistX < ray.sideDistY)
		{
			ray.sideDistX += ray.deltaDistX;
			ray.mapX += ray.stepX;
			ray.side = 0;
		}
		else
		{
			ray.sideDistY += ray.deltaDistY;
			ray.mapY += ray.stepY;
			ray.side = 1;
		}
		if (game->map[ray.mapY][ray.mapX] > '0')
			ray.hit = 1;
	}

	if (ray.side == 0)
		ray.perpWallDist = (ray.mapX - game->player.x + (1 - ray.stepX) / 2) / ray.ray_dir_x;
	else
		ray.perpWallDist = (ray.mapY - game->player.y + (1 - ray.stepY) / 2) / ray.ray_dir_y;

}
