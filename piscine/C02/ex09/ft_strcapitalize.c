/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:19:47 by sanghan           #+#    #+#             */
/*   Updated: 2022/01/13 21:43:20 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c >= 'A' && c <= 'Z')
		{
			c += 32;
		}
		str[i] = c;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	char	c;
	char	d;

	ft_strlowcase(str);
	i = 1;
	while (str[i] != '\0')
	{
		c = str[i];
		d = str[i - 1];
		if (d < '0' || (d > '9' && d < 'A') || (d > 'Z' && d < 'a') || d > 'z')
		{
			if (c >= 'a' && c <= 'z')
			{
				c -= 32;
			}
		}
		str[i] = c;
		i++;
	}
	if (str[0] >= 'a' && str[0] <= 'z')
	{
		str[0] -= 32;
	}
	return (str);
}
