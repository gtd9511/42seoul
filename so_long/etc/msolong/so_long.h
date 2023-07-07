#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "fcntl.h"

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17

# define ESC_KEY 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2

# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define EMPTY '0'
# define WALL '1'

# define SONIC "img/sonic_run_ahead_right1.xpm"
# define IMG_WALL "img/wall.xpm"
# define IMG_EMPTY "img/empty.xpm"
# define IMG_COIN "img/coin.xpm"
# define IMG_EXIT "img/exit.xpm"
# define IMG_ENTRY "img/entry.xpm"

typedef struct s_pointer
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_pointer_set;

typedef struct s_map
{
	int		exit_count;
	int		entry_count;
	int		collectible_count;
	int		width;
	int		height;
	char	**table;
}	t_map;

typedef struct s_img
{
	void	*wall;
	void	*empty;
	void	*coin;
	void	*exit;
	void	*entry;
	void	*sonic;
}	t_img;

typedef struct s_game_information
{
	t_img			*img;
	t_map			*map;
	t_pointer_set	*set;
	int				mv_count;
	int				p_count;
}	t_info;

/*********************************************************
***********    Functions for init structure    ***********
*********************************************************/
t_pointer_set	*init_pointer_set(t_map *map);
t_map			*init_map(char *line);
t_img			*init_img(void *mlx);
t_info			*init_information(t_img *img, t_pointer_set *set, t_map *map);
/*********************************************************
***********    Functions for validate data    ************
*********************************************************/
t_map			*validator(int ac, char **av);
void			verify_border(t_map *map);
void			switch_case_about_map(t_map *map);
/*********************************************************
***********    Functions for exit progress    ************
*********************************************************/
int				exit_on_error(char *str);
/*********************************************************
***********    Functions for rendering map    ************
*********************************************************/
void			render_map(t_map *map, void *mlx, void *win, t_img *img);
/*********************************************************
***********    Functions for game progress    ************
*********************************************************/
int				game_clear_exit(t_info *info);
int				keypress_in_game(int keycode, t_info *info);
int				esc_game_exit(t_info *info);

int				keypress_right(t_info *info);
int				keypress_up(t_info *info);
int				keypress_down(t_info *info);
int				keypress_left(t_info *info);
/*********************************************************
***********    Functions for utilities    	**************
*********************************************************/
void			collectible_counter(t_info *info);
char			*string_join(char *s1, char *s2);
void			free_all_information(t_info *info);

#endif
