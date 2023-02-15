/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:07:15 by sanghan           #+#    #+#             */
/*   Updated: 2022/01/26 19:43:55 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	is_in_base(char str, char *base);
int	ft_check_base(char *base);

int	ft_fbtoi(char *str, char *base_from, int from_baselen)
{
	int	result;
	int	sign;
	int	value;

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
	while (*str != '\0')
	{
		value = is_in_base(*str, base_from);
		if (value == -1)
			break ;
		result = result * from_baselen + value;
		str++;
	}
	return (sign * result);
}

void	ft_itotb(char *dest, int result, char *base_to, int *idx)
{
	unsigned int	to_baselen;
	unsigned int	u_result;

	to_baselen = ft_strlen(base_to);
	if (result < 0)
	{
		dest[*idx] = '-';
		u_result = -result;
		*idx = *idx + 1;
	}
	else
		u_result = result;
	if (u_result > to_baselen - 1)
	{			
		ft_itotb(dest, u_result / to_baselen, base_to, idx);
	}
	dest[*idx] = base_to[u_result % to_baselen];
	*idx = *idx + 1;
	dest[*idx] = '\0';
}

int	ft_getsize(int result, int to_baselen)
{
	int		size;
	long	compare;

	size = 0;
	compare = result;
	if (compare < 0)
	{	
		size += 1;
		compare = -compare;
	}
	while (compare > 0)
	{
		compare /= to_baselen;
		size++;
	}
	return (size + 1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*dest;
	int		destlen;
	int		baselen;
	int		result;
	int		idx;

	idx = 0;
	baselen = ft_strlen(base_from);
	if (ft_check_base(base_from) != 1 || ft_check_base(base_to) != 1)
		return (0);
	result = ft_fbtoi(nbr, base_from, baselen);
	baselen = ft_strlen(base_to);
	destlen = ft_getsize(result, baselen);
	dest = (char *)malloc(sizeof(char) * (destlen));
	ft_itotb(dest, result, base_to, &idx);
	return (dest);
}
