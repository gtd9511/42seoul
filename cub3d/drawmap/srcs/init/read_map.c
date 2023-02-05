/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:52:43 by doykim            #+#    #+#             */
/*   Updated: 2023/02/04 02:53:49 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
//플레이어 위치가 없는 경우
void	read_map(char **temp, t_game *game)
{
	int	i;
	int	j;
	int	len;

	i = 6;
	j = 0;
	len = ft_strlen_2d(temp) - 6;
	game->map = (char **)malloc(sizeof(char *) * (len + 1));
	while (temp[i])
	{
		game->map[j] = ft_strdup(temp[i++]);
		j++;
	}
	game->map[j] = NULL;
	check_map(game->map, game);

	game->map_height = len;
}

void	check_map(char **temp, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (temp[++i])
	{
		j = -1;
		while (temp[i][++j])
		{
			if (temp[i][j] == '0')
			{
				if (i == 0 || j == 0)
					error_exit(3);
				else if (!temp[i + 1][j] || !temp[i][j + 1])
					error_exit(3);
				else if (temp[i][j - 1] == ' ' || temp[i][j + 1] == ' ')
					error_exit(3);
				else if (temp[i + 1][j] == ' ' || temp[i - 1][j] == ' ')
					error_exit(3);
			}
			else if (temp[i][j] != ' ' && temp[i][j] != '1')
				init_player(temp[i][j], i, j, game);
			if (j > game->map_width)
				game->map_width = j;
		}
	}
	game->map_width += 1;
}

void	init_player(char c, int x, int y, t_game *game)
{
	if (game->p_flag)
		error_exit(3);
	else
	{
		game->p_flag = 1;
		if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		{
			game->player.x = x;
			game->player.y = y;
			init_dir(c, game);
		}
		else
			error_exit(3);
	}
}

 void	init_dir(char dir, t_game *game)
 {
 	if (dir == 'N')
 	{
 		game->player.dir_y = -1;
 		game->plane_x = 0.66;
 	}
 	else if (dir == 'S')
 	{
 		game->player.dir_y = 1;
 		game->plane_x = -0.66;
 	}
 	else if (dir == 'W')
 	{
 		game->player.dir_x = -1;
 		game->plane_y = 0.66;
 	}
 	else if (dir == 'E')
 	{
 		game->player.dir_x = 1;
 		game->plane_y = -0.66;
 	}
 }