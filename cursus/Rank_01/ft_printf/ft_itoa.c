/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:59:12 by sanghan           #+#    #+#             */
/*   Updated: 2022/09/01 20:17:49 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	countdigit(long n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	putnbr(long n)
{
	if (n > 9)
		putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int	ft_itoa(int n)
{
	long	l;
	int		size;

	size = 0;
	l = n;
	if (l < 0)
	{
		ft_putchar('-');
		l *= -1;
		size += 1;
	}
	size += countdigit(l);
	putnbr(l);
	return (size);
}

int	ft_uitoa(int n)
{
	unsigned int	u;
	int				size;

	size = 0;
	u = (unsigned int)n;
	size += countdigit(u);
	putnbr(u);
	return (size);
}
