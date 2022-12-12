/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:08:40 by sanghan           #+#    #+#             */
/*   Updated: 2022/12/14 17:26:31 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philo_die(t_philo *philo)
{
	print_state(philo, "is died");
	pthread_mutex_lock(philo->info->over_guard);
	philo->info->over = 1;
	pthread_mutex_unlock(philo->info->over_guard);
	philo->is_die = 1;
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	return (1);
}

int	check_death(t_philo *philo)
{
	long long	now;

	pthread_mutex_lock(philo->info->death);
	now = get_time() - philo->meal;
	if (now >= philo->info->time_die)
	{
		pthread_mutex_unlock(philo->info->death);
		return (philo_die(philo));
	}
	pthread_mutex_unlock(philo->info->death);
	return (0);
}

int	check_meal(t_philo philo, int idx)
{
	if (philo.info->chk_meal && idx == philo.info->num_philo - 1 && \
	philo.eat_cnt == philo.info->must_eat)
		return (ft_usleep(300));
	return (0);
}

void	check_thread(t_info *info, t_philo *philo)
{
	int	i;

	while (!(check_ready_guard(info)))
		continue ;
	while (!(check_over_guard(info)))
	{
		i = 0;
		while (i < info->num_philo)
		{
			if (check_death(&philo[i]) || check_meal(philo[i], i))
			{
				pthread_mutex_lock(philo->info->over_guard);
				info->over = 1;
				pthread_mutex_unlock(philo->info->over_guard);
			}
			i++;
		}
	}
	if (info->chk_meal && philo[info->num_philo - 1].eat_cnt == info->must_eat)
	{
		ft_usleep(5 * info->num_philo);
		printf("eating %d times\n", info->must_eat);
	}
}

void	thread_end(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
	{
		pthread_join(philo[i].thread, (void *)&philo[i]);
		i++;
	}
	pthread_mutex_destroy(info->death);
	pthread_mutex_destroy(info->over_guard);
	pthread_mutex_destroy(info->ready_guard);
	free(info->death);
	free(info->over_guard);
	free(info->ready_guard);
	i = 0;
	while (i < info->num_philo)
	{
		pthread_mutex_destroy(&info->forks[i]);
		i++;
	}
	free(info->forks);
	free(philo);
}
