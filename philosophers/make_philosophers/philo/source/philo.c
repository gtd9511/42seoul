/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:43:50 by sanghan           #+#    #+#             */
/*   Updated: 2022/12/02 11:58:37 by sanghan          ###   ########.fr       */
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
