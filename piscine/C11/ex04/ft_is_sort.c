/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:16:46 by sanghan           #+#    #+#             */
/*   Updated: 2022/01/27 11:34:54 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	inc;
	int	dec;

	i = 0;
	inc = 0;
	dec = 0;
	if (length == 0 || length == 1)
		return (1);
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) <= 0)
			inc++;
		if (f(tab[i], tab[i + 1]) >= 0)
			dec++;
		i++;
	}
	if (i == inc || i == dec)
		return (1);
	else
		return (0);
}			
