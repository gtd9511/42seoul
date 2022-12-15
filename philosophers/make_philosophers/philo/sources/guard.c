/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guard.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:32:34 by sanghan           #+#    #+#             */
/*   Updated: 2022/12/12 20:53:38 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_over_guard(t_info *info)
{
	pthread_mutex_lock(info->over_guard);
	if (info->over == 0)
	{
		pthread_mutex_unlock(info->over_guard);
		return (0);
	}
	pthread_mutex_unlock(info->over_guard);
	return (1);
}

int	check_ready_guard(t_info *info)
{
	pthread_mutex_lock(info->ready_guard);
	if (info->ready == 0)
	{
		pthread_mutex_unlock(info->ready_guard);
		return (0);
	}
	pthread_mutex_unlock(info->ready_guard);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_info	info;

	memset(&info, 0, sizeof(t_info));
	if ((argc != 5 && argc != 6) || init_input(&info, argc, argv))
	{
		printf("Error\n");
		return (1);
	}
	if (philo_start(&info))
		return (1);
	return (0);
}
