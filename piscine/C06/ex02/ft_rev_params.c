/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:01:39 by sanghan           #+#    #+#             */
/*   Updated: 2022/01/20 20:18:10 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_params(char *str)
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
	int	i;

	i = argc;
	if (argc > 1)
	{
		while (i > 1)
		{
			ft_rev_params(argv[i - 1]);
			i--;
		}
	}
}
