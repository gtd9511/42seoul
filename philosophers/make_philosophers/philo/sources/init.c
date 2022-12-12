/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:18:13 by sanghan           #+#    #+#             */
/*   Updated: 2022/12/14 16:29:48 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philo_start(t_info *info)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * info->num_philo);
	if (!philo)
		return (1);
	init_philo(info, philo);
	if (init_thread(info, philo))
		return (1);
	check_thread(info, philo);
	thread_end(info, philo);
	return (0);
}

int	init_thread(t_info *info, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < info->num_philo)
	{
		philo[i].right = philo[(i + 1) % info->num_philo].left;
		if (pthread_create(&philo[i].thread, NULL, \
		&philo_loop, &philo[i]) == -1)
			return (error_free("Error\n", info, philo, info->num_philo));
	}
	i = -1;
	info->start = get_time();
	while (++i < info->num_philo)
	{
		philo[i].t_start = info->start;
		philo[i].meal = info->start;
	}
	pthread_mutex_lock(info->ready_guard);
	info->ready = 1;
	pthread_mutex_unlock(info->ready_guard);
	return (0);
}

void	init_philo(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
	{
		philo[i].p_id = i + 1;
		philo[i].eat_cnt = 0;
		philo[i].t_start = 0;
		philo[i].meal = 0;
		philo[i].info = info;
		philo[i].left = &info->forks[i];
		philo[i].is_die = 0;
		philo[i].right = 0;
		i++;
	}
}

int	init_mutexes(t_info *info)
{
	int	i;

	i = -1;
	info->over_guard = malloc(sizeof(pthread_mutex_t));
	if (!info->over_guard)
		return (error_free("Error\n", info, 0, 0));
	info->ready_guard = malloc(sizeof(pthread_mutex_t));
	if (!info->ready_guard)
		return (error_free("Error\n", info, 0, 0));
	info->death = malloc(sizeof(pthread_mutex_t));
	if (!info->death)
		return (error_free("Error\n", info, 0, 0));
	info->forks = malloc(sizeof(pthread_mutex_t) * info->num_philo);
	if (!info->forks)
		return (error_free("Error\n", info, 0, 0));
	if (pthread_mutex_init(info->over_guard, NULL) == -1 \
		|| pthread_mutex_init(info->ready_guard, NULL) == -1 \
		|| pthread_mutex_init(info->death, NULL) == -1)
		return (error_free("Error\n", info, 0, 0));
	while (++i < info->num_philo)
	{
		if (pthread_mutex_init(&info->forks[i], NULL) == -1)
			return (error_free("Error\n", info, 0, i));
	}
	return (0);
}

int	init_input(t_info *info, int argc, char *argv[])
{
	int	mutex;

	mutex = -1;
	info->num_philo = ft_atoi(argv[1]);
	info->time_die = ft_atoi(argv[2]);
	info->time_eat = ft_atoi(argv[3]);
	info->time_slp = ft_atoi(argv[4]);
	info->must_eat = -2;
	info->chk_meal = 0;
	info->start = 0;
	info->ready = 0;
	if (argc == 6)
	{
		info->chk_meal = 1;
		info->must_eat = ft_atoi(argv[5]);
	}
	info->over = 0;
	if (info->num_philo > 0)
		mutex = init_mutexes(info);
	return (mutex || info->num_philo <= 0 || info->time_die <= 0 \
	|| info->time_eat <= 0 || info->time_slp <= 0 || info->must_eat == 0);
}
