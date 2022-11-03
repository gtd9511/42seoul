/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:48:04 by sanghan           #+#    #+#             */
/*   Updated: 2022/09/01 22:06:48 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	callspecifier(char c, va_list ap)
{
	unsigned long long	p;

	if (c == 'c')
		return (ft_putchar((char)va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(ap, int), c));
	else if (c == 'd' || c == 'i')
		return (ft_itoa(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_uitoa(va_arg(ap, int)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'p')
	{
		p = va_arg(ap, unsigned long long);
		if (p == 0)
			return (ft_putstr("0x0"));
		else
			return (ft_putstr("0x") + ft_putpointer(p));
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		sum;

	if (!str)
		return (0);
	va_start(ap, str);
	i = 0;
	sum = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (!str[i])
				break ;
			sum += callspecifier(str[i], ap);
		}
		else
			sum += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (sum);
}
