/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:18:13 by sanghan           #+#    #+#             */
/*   Updated: 2022/12/02 11:57:43 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_thread(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
	{
		philo[i].p_id = i + 1;
		philo[i].eat_cnt = 0;
	}
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
