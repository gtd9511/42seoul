/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:15:59 by sanghan           #+#    #+#             */
/*   Updated: 2022/01/16 20:39:05 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int		i;
	int		check;
	char	c;

	i = 0;
	check = 1;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c < 'A' || (c > 'Z' && c < 'a') || c > 'z')
		{
			check = 0;
			break ;
		}
		i++;
	}
	return (check);
}
