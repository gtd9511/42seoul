/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:43:36 by sanghan           #+#    #+#             */
/*   Updated: 2022/10/07 18:18:01 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sendsig(int id, int num)
{
	if (num)
		kill(id, SIGUSR1);
	else
		kill(id, SIGUSR2);
}

void	sendbitnum(int id, int num)
{
	int	bit;

	bit = 128;
	while (bit)
	{
		sendsig(id, bit & num);
		bit = bit >> 1;
		usleep(200);
	}
}

void	sigtest(char *pid, char *str)
{
	int	bit;
	int	id;

	id = ft_atoi(pid);
	while (str && ft_strlen(str))
	{
		bit = 128;
		while (bit)
		{
			sendsig(id, bit & *str);
			bit = bit >> 1;
			usleep(200);
		}
		str++;
	}
	sendbitnum(id, 255);
	return ;
}

void	success_ack(int signo)
{
	if (signo == SIGUSR1)
		ft_putstr_fd("SEND SUCCESS\n", 1);
	exit(0);
}

int	main(int argc, char *argv[])
{
	signal(SIGUSR1, success_ack);
	if (argc != 3)
	{
		ft_putstr_fd("SEND FAIL\n", 1);
		exit(0);
	}
	else
		sigtest(argv[1], argv[2]);
	sleep(1);
	write(1, "over 1sec\n", 10);
	return (0);
}
