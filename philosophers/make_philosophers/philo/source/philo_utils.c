/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:08:26 by sanghan           #+#    #+#             */
/*   Updated: 2022/12/02 16:44:01 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

unsigned long	get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

ft_atoi

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	result;
	long long	temp;

	i = 0;
	sign = 1;
	result = 0;
	temp = 0;
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
		temp = result * 10 + (str[i] - '0');
		if (temp < result)
			return (-1 + (sign < 0));
		result = temp;
		i++;
	}
	return ((int)(result * sign));
}

int	my_atoi(const char *str)
{
	size_t			i;
	unsigned long	result;
	unsigned long	op;

	i = 0;
	result = 0;
	op = 1;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		exit_trap(1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
		if ((result > 2147483647 && op == 1))
			exit_trap(1);
	}
	if (str[i])
		exit_trap(1);
	return (result * op);
}
