/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:41:25 by sanghan           #+#    #+#             */
/*   Updated: 2022/01/22 15:25:34 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (nb == 0)
	{
		if (power == 0)
			return (1);
		else
			return (0);
	}
	else
	{
		if (power < 0)
			return (0);
		else if (power == 0)
			return (1);
		else if (power == 1)
			return (nb);
		else if (power > 1)
			return (nb * ft_recursive_power(nb, power - 1));
		else
			return (0);
	}
}
