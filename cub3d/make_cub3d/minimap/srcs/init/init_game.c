/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:48:22 by doykim            #+#    #+#             */
/*   Updated: 2023/02/04 12:40:47 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(int ac, char *av[], t_game *game, t_img *img)
{
	ft_memset(game, 0, sizeof(t_game));
	ft_memset(game, 0, sizeof(t_img));
	game->img = img;
	game->movespeed = 0.01;
	game->rotspeed = 0.01;
	/*
	game->p_flag = 0;
	game->map = NULL;
	game->no_path = NULL;
	game->so_path = NULL;
	game->we_path = NULL;
	game->ea_path = NULL;
	game->floor = NULL;
	game->ceil = NULL;
	game->movespeed = 0.01;
	game->rotspeed = 0.01;
	game->plane_x = 0;
	game->plane_y = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->player.dir_x = 0;
	game->player.dir_y = 0;
	*/
	check_file(ac, av, game);
}
