/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:18:13 by sanghan           #+#    #+#             */
/*   Updated: 2022/01/13 10:38:36 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int		i;
	int		check;
	char	c;

	i = 0;
	check = 1;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c < 32 || c > 126)
		{
			check = 0;
			break ;
		}
		i++;
	}
	return (check);
}
