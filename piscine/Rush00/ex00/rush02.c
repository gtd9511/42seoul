/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 08:19:18 by sanghan           #+#    #+#             */
/*   Updated: 2022/01/10 09:22:05 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_full(char start, char mid, char end, int x)
{
	int	i;

	i = 0;
	ft_putchar(start);
	if (x != 1)
	{
		while (i < x - 2)
		{
			ft_putchar(mid);
			i++;
		}
		ft_putchar(end);
	}
	ft_putchar('\n');
}

void	ft_print_mid(char mid, int x, int y)
{
	int	i;

	i = 0;
	while (i < y - 2)
	{
		ft_print_full(mid, ' ', mid, x);
		i++;
	}
}

void	rush(int x, int y)
{
	if (x > 0 && y > 0)
	{
		ft_print_full('A', 'B', 'A', x);
		if (y != 1)
		{
			ft_print_mid('B', x, y);
			ft_print_full('C', 'B', 'C', x);
		}
	}
}
