/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 04:29:13 by sanghan           #+#    #+#             */
/*   Updated: 2022/11/03 18:42:58 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_info(t_map *info)
{
	info->lines = 0;
	info->c_cnt = 0;
	info->all_c = 0;
	info->p_cnt = 0;
	info->e_cnt = 0;
	info->step = 0;
}

int	free_lines_fd(char **lines, char **row, int fd, int result)
{
	free(*lines);
	free(*row);
	close(fd);
	return (result);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	info;
	char	*ptr;

	if (argc != 2)
		error_exit("The number of parameters is in error");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_exit("Can't open file");
	ptr = ft_strrchr(argv[1], '.');
	if (!ptr || ft_memcmp(ptr, ".ber", 5) != 0)
		error_exit("This file is not ber format");
	if (get_map(&info, fd) > 0 && check_map(&info) > 0 && info.all_c > 0)
	{
		info.mlx_ptr = mlx_init();
		if (!info.mlx_ptr)
			free_exit("Can't init window", &info);
		draw_window(&info);
	}
	else
		error_exit("Error");
	return (0);
}
