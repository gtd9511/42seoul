/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:43:40 by sanghan           #+#    #+#             */
/*   Updated: 2022/10/07 19:05:14 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	endline(int id)
{
	write(1, "\n", 1);
	kill(id, SIGUSR1);
}

void	handler(int signo, siginfo_t *info, void *context)
{
	static int		temp;
	static int		bit;

	(void)context;
	if (bit < 8)
	{
		temp = temp << 1;
		if (signo == SIGUSR1)
			temp = temp | 1;
		bit++;
	}
	if (bit >= 8)
	{
		if (temp != 255)
			write(1, &temp, 1);
		else
			endline(info->si_pid);
		temp = 0;
		bit = 0;
	}
	return ;
}

int	main(void)
{
	struct sigaction	sigact;

	sigact.sa_sigaction = handler;
	sigact.sa_flags = SA_SIGINFO;
	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	while (1)
		pause();
	return (0);
}
