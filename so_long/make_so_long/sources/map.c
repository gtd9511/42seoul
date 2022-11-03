/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 04:44:35 by sanghan           #+#    #+#             */
/*   Updated: 2022/11/03 18:44:43 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_loop(char **temp, char **lines, char **row, int fd)
{
	*temp = (char *)malloc(sizeof(char) * ft_strlen(*lines) + 1);
	ft_strlcpy(*temp, *lines, ft_strlen(*lines) + 1);
	free(*lines);
	*lines = ft_strjoin(*temp, *row);
	free(*temp);
	free(*row);
	*row = get_next_line(fd);
	if (!*row)
		return (-1);
	*temp = ft_strtrim(*row, "\n");
	return (1);
}

int	get_map(t_map *info, int fd)
{
	char	*lines;
	char	*row;
	char	*tmp;

	row = get_next_line(fd);
	if (!row)
		error_exit("Empty row Error\n");
	init_info(info);
	tmp = ft_strtrim(row, "\n");
	info->len = ft_strlen(tmp);
	free(tmp);
	lines = ft_strdup("");
	while (row)
	{
		if (map_loop(&tmp, &lines, &row, fd) < 0)
			break ;
		if ((info->len != (int)ft_strlen(tmp)))
		{
			free(tmp);
			return (free_lines_fd(&lines, &row, fd, -1));
		}
		free(tmp);
	}
	info->map = ft_split(lines, '\n');
	return (free_lines_fd(&lines, &row, fd, 1));
}

int	check_map(t_map *info)
{
	char	**lines;
	int		idx;
	int		l_idx;

	lines = info->map;
	l_idx = 0;
	while (*lines)
	{
		idx = 0;
		while (idx < info->len)
		{
			if ((l_idx == 0 || l_idx == (info->lines) - 1 \
			|| idx == 0 || idx == info->len - 1) && (*lines)[idx] != '1')
				return (-1);
			else if (elem_check(info, (*lines)[idx]) == -1)
				return (-1);
			idx++;
		}
		lines++;
		info->lines++;
		l_idx++;
	}
	if (info->all_c < 1 || info->p_cnt < 1 || info->e_cnt < 1)
		error_exit("The number of elements is an error");
	return (1);
}

void	free_map(t_map *info)
{
	char	**map;

	map = info->map;
	while (*map)
	{
		free(*map);
		*map = NULL;
		map++;
	}
	free(info->map);
	info->map = NULL;
}

int	elem_check(t_map *info, char elem)
{
	if (elem == '1' || elem == '0')
		return (1);
	else if (elem == 'P')
	{
		if (++(info->p_cnt) == 1)
			return (1);
		else
			return (-1);
	}
	else if (elem == 'C')
	{
		info->all_c++;
		return (1);
	}
	else if (elem == 'E')
	{
		if (++(info->e_cnt) == 1)
			return (1);
		else
			return (-1);
	}
	else
		return (-1);
}
