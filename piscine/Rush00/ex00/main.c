/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 08:24:05 by sanghan           #+#    #+#             */
/*   Updated: 2022/01/22 20:49:53 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	rush(int x, int y);

int	ft_number(char *str)
{
	long long	result;

	if (*str == '+')
		str++;
	if (*str >= '1' && *str <= '9')
	{
		result = 0;
		while (*str >= '0' && *str <= '9')
		{
			result = result * 10 + *str - '0';
			str++;
		}
		if (*str != '\0')
			return (-2);
		if (result > 2147483647)
		{
			write(1, "Too big", 7);
			return (-1);
		}
		return (result);
	}
	else
		return (-2);
}

void	print_error(void)
{
	write(1, "Please enter only positive integer\n", 35);
}

int	main(int argc, char *argv[])
{
	int		row;
	int		col;

	if (argc == 1)
		rush(5, 3);
	else if (argc == 3)
	{
		row = ft_number(argv[1]);
		col = ft_number(argv[2]);
		if (row == -1 || col == -1)
			return (0);
		else if (row == -2 || col == -2)
			print_error();
		else
			rush(row, col);
	}
	else
		write(1, "Please enter only 2 values\n", 26);
	return (0);
}
