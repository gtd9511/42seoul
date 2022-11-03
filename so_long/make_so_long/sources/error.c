/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 04:44:31 by sanghan           #+#    #+#             */
/*   Updated: 2022/11/03 18:02:09 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_exit(const char *str)
{
	printf("%s\n", str);
	exit(1);
}

void	free_exit(const char *str, t_map *info)
{
	free_map(info);
	printf("%s\n", str);
	exit(1);
}
