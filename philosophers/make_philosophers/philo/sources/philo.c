/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:43:50 by sanghan           #+#    #+#             */
/*   Updated: 2022/12/10 20:39:26 by sanghan          ###   ########.fr       */
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
	printf("%lld %d %s\n", get_time() - philo->t_start, philo->p_id, str);
	pthread_mutex_unlock(philo->info->death);
}

void	sleep_think(t_philo *philo)
{
	print_state(philo, "is sleeping");
	ft_usleep(philo->info->time_slp);
	print_state(philo, "is thinking");
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	print_state(philo, "has taken a fork");
	pthread_mutex_lock(philo->right);
	print_state(philo, "has taken a fork");
	philo->meal = get_time();
	print_state(philo, "is eating");
	ft_usleep(philo->info->time_eat);
	philo->eat_cnt++;
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

void	*philo_loop(void *job)
{
	t_philo	*philo;

	philo = (t_philo *)job;
	while (!philo->info->ready)
		continue ;
	if (philo->p_id % 2 == 0)
		ft_usleep(philo->info->time_eat * 0.9 + 1);
	while (!philo->info->over)
	{
		eating(philo);
		sleep_think(philo);
	}
	return (NULL);
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
