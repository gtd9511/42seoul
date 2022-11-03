/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 09:51:11 by sanghan           #+#    #+#             */
/*   Updated: 2022/11/03 19:37:33 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../mlx/mlx.h"

# define LEN 32
# define X_EVENT_KEY_RELEASE		3
# define X_EVENT_KEY_EXIT   17
# define ESC_KEY		53
# define W_KEY			13
# define A_KEY			0
# define S_KEY			1
# define D_KEY			2

typedef struct map {
	int		len;
	int		lines;
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*l_ptr;
	void	*p_ptr;
	void	*w_ptr;
	void	*e_ptr;
	void	*c_ptr;
	int		all_c;
	int		c_cnt;
	int		p_cnt;
	int		e_cnt;
	int		step;
}	t_map;

typedef struct s_param
{
	int	x;
	int	y;
}	t_param;

void	init_info(t_map *info);
int		free_lines_fd(char **lines, char **row, int fd, int result);
int		map_loop(char **temp, char **lines, char **row, int fd);
int		get_map(t_map *info, int fd);
int		check_map(t_map *info);
void	free_map(t_map *info);
int		elem_check(t_map *info, char elem);
void	draw_window(t_map *info);
void	get_ptrs(t_map *info, int *width, int *height);
void	draw_map(t_map *info);
void	draw_image(t_map *info, char elem, int x, int y);
void	draw_image_window(t_map *info, void *draw_ptr, int x, int y);
void	p_coord(t_map *info, int *x, int *y);
void	clear_exit(t_map *info);
int		exit_game(t_map *info);
int		press_key(int keydown, t_map *info);
void	key_w(t_map *info);
void	key_s(t_map *info);
void	key_a(t_map *info);
void	key_d(t_map *info);
void	error_exit(const char *str);
void	free_exit(const char *str, t_map *info);
#endif
