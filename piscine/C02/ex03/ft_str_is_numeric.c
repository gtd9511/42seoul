/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:37:02 by sanghan           #+#    #+#             */
/*   Updated: 2022/01/13 21:43:01 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int		i;
	int		check;
	char	c;

	i = 0;
	check = 1;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c < '0' || c > '9')
		{
			check = 0;
			break ;
		}
		i++;
	}
	return (check);
}
