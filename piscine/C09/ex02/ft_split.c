/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:08:35 by sanghan           #+#    #+#             */
/*   Updated: 2022/01/26 20:52:04 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_check_sep(char str, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == str)
			return (1);
		i++;
	}
	return (0);
}

int	ft_split_size(char *str, char *charset)
{
	int	i;
	int	size;

	size = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_check_sep(str[i], charset) == 0)
		{
			size++;
			while (str[i] != '\0' && ft_check_sep(str[i], charset) == 0)
				i++;
		}
		i++;
	}
	return (size);
}

void	ft_copy(char *set_idx, char *str, char *split)
{
	while (set_idx < str)
		*(split++) = *(set_idx++);
	*split = '\0';
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	char	*set_idx;	
	int		sp_idx;

	sp_idx = 0;
	split = (char **)malloc(sizeof(char *) * (ft_split_size(str, charset) + 1));
	if (split == 0)
		return (0);
	while (*str != '\0')
	{
		if (ft_check_sep(*str, charset) == 0)
		{
			set_idx = str;
			while (*str != '\0' && ft_check_sep(*str, charset) == 0)
				str++;
			split[sp_idx] = (char *)malloc(sizeof(char) * (str - set_idx + 1));
			if (split[sp_idx] == NULL)
				return (NULL);
			ft_copy(set_idx, str, split[sp_idx]);
			sp_idx++;
		}
		str++;
	}
	split[sp_idx] = 0;
	return (split);
}
