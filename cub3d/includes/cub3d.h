/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:32:29 by doykim            #+#    #+#             */
/*   Updated: 2023/01/25 18:15:34 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define KEY_ESC	53
# define KEY_W		13
# define KEY_S		1
# define KEY_A		0
# define KEY_D		2
# define KEY_LEFT	123
# define KEY_RIGHT	124

# define true 1
# define false 0


typedef struct s_player
{
	int		x;
	int		y;
	char	dir;
}	t_player;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			p_flag;
	char		**map;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	t_rgb		floor;
	t_rgb		ceil;
	t_player	player;
}	t_game;

typedef struct s_data
{
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

/*
typedef struct s_img
{
	void	*image;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		*buffer;
}	t_img;

typedef struct s_ray
{
	int		map_x;
	int		map_y;
	int		hit;
	int		side;
	int		step_x;
	int		step_y;
	double	camera_x;
	double	camera_y;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	double	wall_x;
	int		texture_x;
	int		texture_y;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	step;
	double	texture_pos;
}	t_ray;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	t_img	*img;
	t_ray	*ray;
	char	*line;
	char	*texture_no;
	char	*texture_so;
	char	*texture_we;
	char	*texture_ea;
	t_img	img_no;
	t_img	img_so;
	t_img	img_we;
	t_img	img_ea;
	int		*f;
	int		*c;
	int		f_hex;
	int		c_hex;
	int		map_height;
	int		map_width;
	char	**map;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_game;
*/
//init
void	init_game(int ac, char *av[], t_game *game);

void	check_file(int ac, char **av, t_game *game);
void	check_argument(int ac, char **av);

void	init_element(char *buff, t_game *game);
void	init_texture(t_game *game, char *line);
int		check_texture(char *line, char **tmp);
void	init_rgb(t_game *game, char *line);
void	check_rgb_num(char **temp);

void	read_map(char **temp, t_game *game);
void	check_map(char **temp, t_game *game);
void	init_player(char c, int x, int y, t_game *game);

//key
int		key_press(int keycode, t_game *game);
void	move(t_game *game, int dx, int dy);
int		x_exit(int n);

//utils
void	error_exit(int n);
void	free_2d_array(char **str);
void	print_2d(char **arr);

#endif
