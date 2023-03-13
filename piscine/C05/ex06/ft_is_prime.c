/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:42:57 by sanghan           #+#    #+#             */
/*   Updated: 2022/01/20 21:06:35 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	temp;

	temp = 2;
	if (nb < 2)
		return (0);
	while (temp < 46341 && temp < nb)
	{
		if (nb % temp == 0)
			return (0);
		temp++;
	}
	return (1);
}