/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:15:00 by sanghan           #+#    #+#             */
/*   Updated: 2022/01/20 16:57:23 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_check_base(char *base, int baselen)
{
	int	i;
	int	j;

	i = 0;
	if (baselen < 2)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ' \
				|| base[i] == '\t' || base[i] == '\n' || base[i] == '\v' \
				|| base[i] == '\f' || base[i] == '\r')
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

int	is_in_base(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == str)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi(char *str, char *base, int baselen)
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
		value = is_in_base(*str, base);
		if (value == -1)
			break ;
		result = result * baselen + value;
		str++;
	}
	return (sign * result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	baselen;
	int	check;
	int	result;

	result = 0;
	baselen = ft_strlen(base);
	check = ft_check_base(base, baselen);
	if (check == 1)
	{
		result = ft_atoi(str, base, baselen);
	}
	else
		return (0);
	return (result);
}
