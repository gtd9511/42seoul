/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:59:23 by sanghan           #+#    #+#             */
/*   Updated: 2022/09/01 20:17:52 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	charcount(unsigned long long nb)
{
	int	i;

	i = 1;
	while (nb >= 16)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

void	putnbr_base(unsigned long long nb, char *base)
{
	if (nb >= 16)
		putnbr_base((nb / 16), base);
	ft_putchar(base[nb % 16]);
}

int	ft_puthex(int i, char x)
{
	char			*base;
	int				sum;
	unsigned int	c;

	base = "0123456789abcdef";
	if (x == 'X')
		base = "0123456789ABCDEF";
	sum = 0;
	c = (unsigned int)i;
	putnbr_base(c, base);
	sum += charcount(c);
	return (sum);
}
