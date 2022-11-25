/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:18:13 by sanghan           #+#    #+#             */
/*   Updated: 2022/11/30 15:26:59 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_thread(t_philo *philo, t_thread *thread)
{
	int	i;

	i = 0;
	while (i < philo->num_philo)
	{
		thread[i].p_id = i + 1;
		thread[i].eat_cnt = 0;

	}
}
int	init_input(t_philo *philo, int argc, char *argv[])
{
	int	mutex;

	mutex = -1;
	philo->num_philo = ft_atoi(argv[1]);
	philo->time_die = ft_atoi(argv[2]);
	philo->time_eat = ft_atoi(argv[3]);
	philo->time_slp = ft_atoi(argv[4]);
	philo->must_eat = -2;
	philo->chk_meal = 0;
	philo->start = 0;
	philo->ready = 0;
	if (argc == 6)
	{
		philo->chk_meal = 1;
		philo->must_eat = ft_atoi(argv[5]);
	}
	philo->over = 0;
	if (philo->num_philo > 0)
		mutex = init_mutexes(philo);
	return (mutex || philo->num_philo <= 0 || philo->time_die <= 0 \
	|| philo->time_eat <= 0 || philo->time_slp <= 0 || philo->must_eat == 0);
}
