/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:06:21 by sanghan           #+#    #+#             */
/*   Updated: 2022/01/25 19:00:24 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_set_arr(int size, char *dest, char **strs, char *sep)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (*strs[i])
			dest[j++] = *(strs[i]++);
		if (i != size - 1)
		{
			k = 0;
			while (*(sep + k))
				dest[j++] = *(sep + k++);
		}
		i++;
	}
	dest[j] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		destlen;
	int		i;

	i = 0;
	destlen = 0;
	while (i < size)
		destlen += ft_strlen(strs[i++]);
	if (size <= 0)
		destlen = 1;
	else
		destlen += ft_strlen(sep) * (size - 1) + 1;
	dest = (char *)malloc(sizeof(char) * destlen);
	if (dest == 0)
		return (0);
	ft_set_arr(size, dest, strs, sep);
	return (dest);
}
