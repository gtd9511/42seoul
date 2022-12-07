/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:08:26 by sanghan           #+#    #+#             */
/*   Updated: 2022/12/07 16:04:21 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_usleep(int time)
{
	long long	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < time)
		usleep(150);
	return (1);
}

unsigned long	get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

void	error_exit(int type)
{
	pirntf("Error\n");
	exit(type);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = 0;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
		if (result > 2147483647 && sign == 1)
			error_exit(1);
	}
	if (str[i])
		error_exit(1);
	return ((int)(result * sign));
}

int	error_free(char *str, t_info *info, t_philo *philo, int cnt)
{
	int	i;

	i = 0;
	if (info->num_philo > 0 && info->death)
	{
		pthread_mutex_destroy(info->death);
		free(info->death);
	}
	if (info->num_philo > 0 && info->forks)
	{
		while (i < cnt)
		{
			pthread_mutex_destroy(&info->forks[i]);
			i++;
		}
		free(info->forks);
	}
	if (philo)
		free(philo);
	printf("%s", str);
	return (1);
}
