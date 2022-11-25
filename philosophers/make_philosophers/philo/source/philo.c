/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:43:50 by sanghan           #+#    #+#             */
/*   Updated: 2022/11/30 15:24:28 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philo_start(t_philo *philo)
{
	t_thread	*thread;

	thread = malloc(sizeof(t_thread) * philo->num_philo);
	if (!thread)
		return (1);
	init_philo(philo, thread);
	if (init_thread(philo, thread))
		return (1);
	check_thread(philo, thread);
	thread_end(philo, thread);
	return (0);
}


int	main(int argc, char *argv[])
{
	t_philo	philo;

	memset(&philo, 0, sizeof(philo));
	if ((argc != 5 && argc != 6) || init_input(&philo, argc, argv))
	{
		printf("Error\n");
		return (1);
	}
	if (philo_start(&philo))
		return (1);
	return (0);
}
