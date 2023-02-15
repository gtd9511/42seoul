/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:40:56 by sanghan           #+#    #+#             */
/*   Updated: 2022/01/22 15:25:18 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	temp;

	temp = 1;
	if (nb == 0)
	{
		if (power == 0)
			return (1);
		else
			return (0);
	}
	else
	{
		while (power > 0)
		{
			temp = temp * nb;
			power--;
		}
		if (power < 0)
			return (0);
	}
	return (temp);
}
