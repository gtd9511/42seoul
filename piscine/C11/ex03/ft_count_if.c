/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:12:43 by sanghan           #+#    #+#             */
/*   Updated: 2022/01/27 10:43:07 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int(*f)(char *))
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			cnt++;
		i++;
	}
	return (cnt);
}
