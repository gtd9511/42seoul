/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 08:26:40 by sanghan           #+#    #+#             */
/*   Updated: 2022/11/03 04:56:41 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#	define X_EVENT_KEY_PRESS		2
#	define X_EVENT_KEY_RELEASE		3

#	define KEY_ESC					53
#	define KEY_W					13
#	define KEY_A					0
#	define KEY_S					1
#	define KEY_D					2

void	param_init(t_param	*param)
{
	param->x = 3;
	param->y = 4;
}

int	key_press(int keycode, t_param *param)
{
	static int	a = 0;

	if (keycode == KEY_W)
		param->y++;
	else if (keycode == KEY_S)
		param->y--;
	else if (keycode == KEY_A)
		param->x++;
	else if (keycode == KEY_D)
		param->x--;
	else if (keycode == KEY_ESC)
		exit (0);
	printf("x: %d, y : %d\n", param->x, param->y );
	return (0);
}

void	map_read(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	game->hei = 0;
	game->wid = ft_strlen(line) - 1;
	game->str_line = ft_strdup(line);
	free(line);
	while (line)
	{
		game->hei++;
		line = get_next_line(fd);
		if (line)
			game->str_line = ft_strjoin(game->str_line, line);
	}
	close(fd);
	printf("%s\n", game->str_line);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	void	*img6;
	void	*img7;
	void	*img8;
	void	*img9;
	int		img_width;
	int		img_height;

	t_param	param;

	param_init(&param);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "so long");
	img1 = mlx_xpm_file_to_image(mlx_ptr, "./images/coin1.xpm", &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(mlx_ptr, "./images/coin2.xpm", &img_width, &img_height);
	img3 = mlx_xpm_file_to_image(mlx_ptr, "./images/coin3.xpm", &img_width, &img_height);
	img4 = mlx_xpm_file_to_image(mlx_ptr, "./images/coin4.xpm", &img_width, &img_height);
	img5 = mlx_xpm_file_to_image(mlx_ptr, "./images/gomba.xpm", &img_width, &img_height);
	img6 = mlx_xpm_file_to_image(mlx_ptr, "./images/load.xpm", &img_width, &img_height);
	img7 = mlx_xpm_file_to_image(mlx_ptr, "./images/mario.xpm", &img_width, &img_height);
	img8 = mlx_xpm_file_to_image(mlx_ptr, "./images/pip.xpm", &img_width, &img_height);
	img9 = mlx_xpm_file_to_image(mlx_ptr, "./images/wall.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img1, 0, 0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img2, 32, 0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img3, 64, 0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img4, 0, 32);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img5, 32, 32);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img6, 64, 32);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img7, 0, 64);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img8, 32, 64);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img9, 64, 64);

	mlx_hook(win_ptr, X_EVENT_KEY_RELEASE, 0, &key_press, &param);
	mlx_loop(mlx_ptr);
}
