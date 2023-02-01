/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:43:27 by doykim            #+#    #+#             */
/*   Updated: 2023/02/01 19:27:41 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main_loop(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->ceil, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->floor, 0, 540);
	raycasting(game);
//	paint_img(game);
//	key_hook(game);
	return (0);
}

