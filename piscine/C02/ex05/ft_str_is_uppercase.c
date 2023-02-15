/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:17:38 by sanghan           #+#    #+#             */
/*   Updated: 2022/01/12 21:04:56 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int		i;
	int		check;
	char	c;

	i = 0;
	check = 1;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c < 'A' || c > 'Z')
		{
			check = 0;
			break ;
		}
		i++;
	}
	return (check);
}
