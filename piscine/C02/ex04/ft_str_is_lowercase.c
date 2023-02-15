/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:17:04 by sanghan           #+#    #+#             */
/*   Updated: 2022/01/12 19:31:58 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int		i;
	int		check;
	char	c;

	i = 0;
	check = 1;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c < 'a' || c > 'z')
		{
			check = 0;
			break ;
		}
		i++;
	}
	return (check);
}
