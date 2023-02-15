/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:21:17 by sanghan           #+#    #+#             */
/*   Updated: 2022/01/18 09:49:50 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char	*str)
{
	int				i;
	unsigned char	c;
	char			d;

	d = 92;
	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (str[i] < 32 || str[i] > 126)
		{
			ft_putchar(d);
			ft_putchar("0123456789abcdef"[c / 16]);
			ft_putchar("0123456789abcdef"[c % 16]);
		}
		else
			ft_putchar(c);
		i++;
	}
}
