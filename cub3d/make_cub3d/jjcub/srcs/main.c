/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:36:32 by jungchoi          #+#    #+#             */
/*   Updated: 2023/02/04 12:55:28 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_game	game;
	t_img	img;

	if (argc != 2)
	{
		ft_printf("check arguments number");
		return (0);
	}
	init_game_struct(&game, &img);
	validate_arg(&game, argv);
	
	parsing_cub_file(&game, argv[1]);
	game.mlx = mlx_init();
	set_texture_image(&game);
	game.img->image = mlx_new_image(game.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (game.img->image == NULL)
		ft_error(&game, "mlx error");
	game.window = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	raycasting(&game);
	mlx_hook(game.window, ON_CLICK, 0, press_key, &game);
	mlx_hook(game.window, ON_DESTROY, 0, click_destroy, &game);
	mlx_loop(game.mlx);
}



//	mlx_hook(game.win, 17, 0, x_exit, &game);
//	mlx_hook(game.win, 2, 0, key_press, &game);
//	mlx_hook(game.win, 3, 0, key_release, &game);
//	printf("@@@@@@@@@@@@@@@@@@@@@@ map_x : %d\n", game.map_x);
//	printf("@@@@@@@@@@@@@@@@@@@@@@ map_y : %d\n", game.map_y);
//	mlx_loop_hook(game.mlx, &main_loop, &game);
//	mlx_loop(game.mlx);
