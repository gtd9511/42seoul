/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:25:54 by sanghan           #+#    #+#             */
/*   Updated: 2022/01/27 14:20:38 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else
	{
		if (nb > 9)
		{
			ft_putnbr(nb / 10);
		}
		ft_putchar(48 + nb % 10);
	}
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	sign = 1;
	result = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' \
			|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (sign * result);
}

void	operator(char c, int n1, int n2)
{
	if (c == '+')
		ft_putnbr(n1 + n2);
	else if (c == '-')
		ft_putnbr(n1 - n2);
	else if (c == '*')
		ft_putnbr(n1 * n2);
	else if (c == '/')
	{
		if (n2 == 0)
		{
			write(1, "Stop : division by zero", 23);
			return ;
		}
		ft_putnbr(n1 / n2);
	}
	else if (c == '%')
	{
		if (n2 == 0)
		{
			write(1, "Stop : modulo by zero", 21);
			return ;
		}
		ft_putnbr(n1 % n2);
	}
}

int	main(int argc, char **argv)
{
	int	value1;
	int	value2;

	if (argc != 4)
		return (-1);
	value1 = ft_atoi(argv[1]);
	value2 = ft_atoi(argv[3]);
	if (argv[2][1])
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (argv[2][0] == '+' || argv[2][0] == '-' || argv[2][0] == '*'
			|| argv[2][0] == '/' || argv[2][0] == '%')
	{
		operator(argv[2][0], value1, value2);
		write(1, "\n", 1);
	}
	else
		write(1, "0\n", 2);
}
