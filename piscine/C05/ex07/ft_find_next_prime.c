/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:43:29 by sanghan           #+#    #+#             */
/*   Updated: 2022/01/20 20:50:56 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_is_prime(int num)
{
	int	temp;

	temp = 2;
	if (num < 2)
		return (0);
	while (temp < 46341 && temp < num)
	{
		if (num % temp == 0)
			return (0);
		temp++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	temp;

	if (nb < 2)
		return (2);
	temp = nb;
	while (ft_is_prime(temp) != 1)
		temp++;
	return (temp);
}
