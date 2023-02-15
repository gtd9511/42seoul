/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:21:54 by sanghan           #+#    #+#             */
/*   Updated: 2022/01/18 14:52:25 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	if (c < 32 || c > 126)
	{
		write(1, ".", 1);
	}
	else
		write(1, &c, 1);
}

void	ft_print_hex(char *str)
{
	int				i;
	unsigned char	c;

	i = 0;
	c = str[i];
	if (str[i] == '\0')
		write(1, "00", 2);
	else
	{
		ft_putchar("0123456789abcdef"[c / 16]);
		ft_putchar("0123456789abcdef"[c % 16]);
	}
}

void	ft_print_addr_hex(unsigned long long int address)
{
	char	addr_char[16];
	int		a;
	int		i;
	int		mod;

	a = 0;
	i = 0;
	while (a++ < 16)
		addr_char[a] = '0';
	while (1)
	{
		mod = address % 16;
		if (mod < 10)
			addr_char[16 - i] = '0' + mod;
		else
			addr_char[16 - i] = 'a' + (mod - 10);
		address /= 16;
		i++;
		if (address == 0)
			break ;
	}
	a = 0;
	while (a++ < 16)
		ft_putchar(addr_char[a]);
}

void	ft_print_hex_contents(unsigned int i, \
	   	unsigned int j, unsigned int size, char *addr_char)
{
	while (j < i + 16 && j < size)
	{
		ft_print_hex(&addr_char[j]);
		if (j % 2 == 1)
			write(1, " ", 1);
		j++;
		if (j > size - 1)
		{
			while (j < i + 16)
			{
				write(1, "  ", 2);
				if (j % 2 == 1)
					write(1, " ", 1);
				j++;
			}
		}
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int			i;
	unsigned int			j;
	char					*addr_char;
	unsigned long long int	address;

	addr_char = (char *)addr;
	address = (unsigned long long int)addr;
	i = 0;
	while (i < size)
	{
		j = i;
		ft_print_addr_hex(address + i);
		write(1, ": ", 2);
		ft_print_hex_contents(i, j, size, addr_char);
		j = i;
		while (j < i + 16 && j < size)
		{
			ft_putchar(addr_char[j]);
			j++;
		}
		write(1, "\n", 1);
		i += 16;
	}	
	return (addr);
}
