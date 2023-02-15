/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 21:11:28 by sanghan           #+#    #+#             */
/*   Updated: 2022/01/11 14:46:38 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_printnum(int num)
{
	ft_putchar(48 + num / 10);
	ft_putchar(48 + num % 10);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;	

	a = 0;
	while (a < 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_printnum(a);
			ft_putchar(' ');
			ft_printnum(b);
			write(1, ", ", 2);
			b++;
		}
		a++;
	}
	write(1, "98 99", 5);
}
