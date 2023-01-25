/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:40:49 by doykim            #+#    #+#             */
/*   Updated: 2023/01/25 17:26:16 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_leak(void)
{
	system("leaks cub3d");
}

int	main(int ac, char *av[])
{
	t_game	game;
	t_data	image;

	atexit(check_leak);
	init_game(ac, av, &game);


	image.img = mlx_new_image(game.mlx, 1920, 1080); // 이미지 객체 생성
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian); // 이미지 주소 할당
	for (int i = 0 ; i < 1920 ; i++)
	{
		for (int j = 0 ; j < 540 ; j++)
		{
			mlx_pixel_put (game.mlx, game.win, i, j, 0x00FFFFFF);
		}
	}

	printf("\n\n"); ///구조체 변수 체크

	print_2d(game.map);

	printf("\nno_path : %s\n", game.no_path);
	printf("so_path : %s\n", game.so_path);
	printf("we_path : %s\n", game.we_path);
	printf("ea_path : %s\n", game.so_path);

	printf("\nfrgb : %d %d %d", game.floor.r, game.floor.g, game.floor.b);
	printf("\ncrgb : %d %d %d\n", game.ceil.r, game.ceil.g, game.ceil.b);

	printf("\nplayer pos : %d, %d\n", game.player.x, game.player.y);
	printf("player dir : %c\n", game.player.dir);

	printf("\n\n-------------------------------\n\n\n");
// 주석 풀면 map뒤에 쓰레기값 들어가면서 map error남
	mlx_hook(game.win, 17, 0, x_exit, &game);
	mlx_hook(game.win, 2, 0, key_press, &game);
	mlx_loop(game.mlx);

	free_2d_array(game.map);
	free(game.no_path);
	free(game.so_path);
	free(game.we_path);
	free(game.ea_path);
	mlx_destroy_window(game.mlx, game.win);

	return (0);
}
