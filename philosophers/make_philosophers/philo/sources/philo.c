/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:43:50 by sanghan           #+#    #+#             */
/*   Updated: 2022/12/12 21:49:07 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_state(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->info->death);
	if (check_over_guard(philo->info))
	{
		pthread_mutex_unlock(philo->info->death);
		return ;
	}
	printf("%lld %d %s\n", get_time() - philo->t_start, philo->p_id, str);
	pthread_mutex_unlock(philo->info->death);
}

void	sleeping(t_philo *philo)
{
	print_state(philo, "is sleeping");
	ft_usleep(philo->info->time_slp);
}

void	thinking(t_philo *philo)
{
	print_state(philo, "is thinking");
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	print_state(philo, "has taken a fork");
	pthread_mutex_lock(philo->right);
	print_state(philo, "has taken a fork");
	pthread_mutex_lock(philo->info->death);
	philo->meal = get_time();
	pthread_mutex_unlock(philo->info->death);
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
	while (!(check_ready_guard(philo->info)))
		continue ;
	if (philo->p_id % 2 == 0)
		ft_usleep(philo->info->time_eat * 0.9 + 1);
	while (!(check_over_guard(philo->info)))
	{
		eating(philo);
		if (philo->eat_cnt == philo->info->must_eat)
		{
			sleeping(philo);
			return (NULL);
		}
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
