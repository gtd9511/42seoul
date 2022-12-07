/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:43:50 by sanghan           #+#    #+#             */
/*   Updated: 2022/12/07 16:15:33 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_state(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->info->death);
	if (philo->info->over)
	{
		pthread_mutex_unlock(philo->info->death);
		return ;
	}
	printf("%lldms %d %s\n", get_time() - philo->t_start, philo->p_id, str);
	pthread_mutex_unlock(philo->info->death);
}

int	main(int argc, char *argv[])
{
	t_info	info;

	memset(&info, 0, sizeof(info));
	if ((argc != 5 && argc != 6) || init_input(&info, argc, argv))
	{
		printf("Error\n");
		return (1);
	}
	if (philo_start(&info))
		return (1);
	return (0);
}
