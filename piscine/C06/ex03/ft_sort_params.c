/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:02:21 by sanghan           #+#    #+#             */
/*   Updated: 2022/01/22 19:14:21 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_sort_params(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*temp;

	j = argc;
	if (argc > 1)
	{
		while (j-- > 1)
		{
			i = 1;
			while (i < argc - 1)
			{	
				if (ft_strcmp(argv[i], argv[i + 1]) > 0)
				{
					temp = argv[i];
					argv[i] = argv[i + 1];
					argv[i + 1] = temp;
				}
				i++;
			}
		}
		i = 0;
		while (i++ < argc - 1)
			ft_sort_params(argv[i]);
	}
}
