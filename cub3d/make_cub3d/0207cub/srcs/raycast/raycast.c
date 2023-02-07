/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:43:27 by doykim            #+#    #+#             */
/*   Updated: 2023/02/07 21:25:20 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_game *game)
{
	t_ray	*ray;
	int		x;

	while (x < WIDTH)
	{
		ray->cameraX = (2 * x / (double)WIDTH) - 1;
		ray->ray_dir_x = game->player.x + game->plane_x * ray->cameraX;
		ray->ray_dir_y = game->player.y + game->plane_y * ray->cameraX;
		ray->mapX = (int)game->player.x;
		ray->mapY = (int)game->player.y;
		if (ray->ray_dir_x != 0)
			ray->deltaDistX = fabs(1 / ray->ray_dir_x);
		if (ray->ray_dir_x != 0)
			ray->deltaDistY = fabs(1 / ray->ray_dir_y);
		ray->hit = 0;

		if (ray->ray_dir_x < 0)
		{
			ray->stepX = -1;
			ray->sideDistX = (game->player.x - ray->mapX) * ray->deltaDistX;
		}
		else
		{
			ray->stepX = 1;
			ray->sideDistX = (ray->mapX + 1.0 - game->player.x) * ray->deltaDistX;
		}
		if (ray->ray_dir_y < 0)
		{
			ray->stepY = -1;
			ray->sideDistY = (game->player.y - ray->mapX) * ray->deltaDistY;
		}
		else{
			ray->stepY = 1;
			ray->sideDistY = (ray->mapY + 1.0 - game->player.y) * ray->deltaDistY;
		}
	}

	ray->mapX = game->player.x;
	ray->mapY = game->player.y;
	while (ray->hit == 0)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		if (game->map[ray->mapY][ray->mapX] > '0')
			ray->hit = 1;
	}

	if (ray->side == 0)
		ray->perpWallDist = (ray->mapX - game->player.x + (1 - ray->stepX) / 2) / ray->ray_dir_x;
	else
		ray->perpWallDist = (ray->mapY - game->player.y + (1 - ray->stepY) / 2) / ray->ray_dir_y;

	int	lineHeight = (int)(HEIGHT / ray->perpWallDist);

	int	drawStart = -lineHeight / 2 + HEIGHT / 2;
	if (drawStart < 0)
		drawStart = 0;
	int drawEnd = lineHeight /2 + 1080 / 2;
	if (drawEnd >= HEIGHT)
		drawEnd = HEIGHT - 1;

	t_img	texture_image;
	t_img	img1;
	t_img	img2;
	t_img	img3;
	t_img	img4;
	if (ray->side == 1 && ray->stepY < 0)
		texture_image = img1;
	else if (ray->side == 1)
		texture_image = img2;
	else if (ray->stepX > 0)
		texture_image = img3;
	else
		texture_image = img4;

	if (ray->side == 0)
		ray->wall_x = game->player.y + ray->perpWallDist * ray->ray_dir_y;
	else
		ray->wall_x = game->player.x + ray->perpWallDist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->texture_x = (int)(ray->wall_x * (double) texture_image.line_len / 4);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->texture_x = texture_image.line_len / 4 -ray->texture_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		ray->texture_x = texture_image.line_len / 4 - ray->texture_x - 1;
	lineHeight = (int)(HEIGHT / ray->perpWallDist);
	drawStart = -1 * lineHeight / 2 + HEIGHT / 2;
	if (drawStart < 0)
		drawStart = 0;
	drawEnd = lineHeight / 2 + HEIGHT / 2;
	if (drawEnd >= HEIGHT)
		drawEnd = HEIGHT;
	ray->step = (double)texture_image.line_len / 4 / lineHeight;
	ray->texture_pos = (drawStart - HEIGHT / 2 + lineHeight / 2) * ray->step;

	int	y;
	int	pixel;
	y = drawStart;
	while (y < drawEnd)
	{
		pixel = (y * game->img->line_len / 4) + x;
		ray->texture_y = (int)ray->texture_pos & (texture_image.line_len / 4 - 1);
		game->img->data[pixel] = texture_image.data[ray->texture_y * texture_image.line_len / 4 + ray->texture_x];
		ray->texture_pos += ray->step;
	}

	//image.data = (int *)mlx_get_data_addr(image.img, &image.bpp, image.line_len, image.endian);
	/*
	t_rgb color;
	if (game->map[ray.mapX][ray.mapX] == '1')
	{
		color.r = 0;
		color.b = 255;
		color.g = 0;
	}
	if (ray.side == 1)
	{
		color.r /= 2;
		color.b /= 2;
		color.g /= 2;
	}
	*/
}
