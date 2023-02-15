/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:13:43 by sanghan           #+#    #+#             */
/*   Updated: 2022/01/20 16:57:33 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_check_base(char *base, unsigned int baselen)
{
	int	i;
	int	j;

	i = 0;
	if (baselen < 2)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		else
		{
			j = 0;
			while (j < i)
			{
				if (base[i] == base[j])
					return (0);
				j++;
			}
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				check;
	unsigned int	baselen;
	unsigned int	nnbr;

	baselen = ft_strlen(base);
	check = ft_check_base(base, baselen);
	if (check == 1)
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nnbr = -nbr;
		}
		else
			nnbr = nbr;
		if (nnbr > (baselen - 1))
		{
			ft_putnbr_base(nnbr / baselen, base);
		}
		ft_putchar(base[nnbr % baselen]);
	}
}
