/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:43:51 by sanghan           #+#    #+#             */
/*   Updated: 2022/12/19 19:27:15 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
/*
int	show_draw(void)
{
	char			*line;
	int				fd;
	int				i;

	fd = open("shanghai.txt", O_RDONLY);
	if (!fd)
		return (1);
	i = 0;
	while (i++ < 300)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	close(fd);
//system("leaks a.out");
	return (0);
}

int	show_shanghai(void)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open("shanghai_ascii", O_RDONLY);
	if (!fd)
		return (1);
	while (i++ < 300)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	close(fd);
	free(line);
	return (0);
}

int	main(int argc, char *argv [], char *envp[])
{
	char	**g_envp;

	g_envp = envp;
	(void)argc;
	(void)argv;
	(void)g_envp;
	show_draw();

	return (0);
}
*/
int	main(void)
{
	char			*line;
	int				fd;
	int				i;

	fd = open("shanghai.txt", O_RDONLY);
	if (!fd)
		return (1);
	i = 0;
	while (i++ < 300)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		printf("%s", line);
		free(line);
	}
	close(fd);
//	system("leaks a.out");
	return (0);
}
