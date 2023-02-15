/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:20:24 by sanghan           #+#    #+#             */
/*   Updated: 2022/01/13 21:43:59 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	temp;

	temp = ft_strlen(src);
	i = 0;
	if (!dest || !src)
		return (0);
	if (size != 0)
	{
		while (i < temp && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
	}
	if (size > 0)
		dest[i] = '\0';
	return (temp);
}
