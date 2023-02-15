/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:01:32 by sanghan           #+#    #+#             */
/*   Updated: 2022/01/24 15:17:42 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*newstr;
	int		i;

	i = ft_strlen(src);
	newstr = (char *)malloc(sizeof(char) * (i + 1));
	if (newstr == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (src[i] != '\0')
		{
			newstr[i] = src[i];
			i++;
		}
		newstr[i] = '\0';
		return (newstr);
	}
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*temp;
	int			i;

	i = 0;
	temp = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (temp == NULL)
		return (NULL);
	while (i < ac)
	{
		temp[i].size = ft_strlen(av[i]);
		temp[i].str = av[i];
		temp[i].copy = ft_strdup(av[i]);
		i++;
	}
	temp[i].str = 0;
	return (temp);
}
