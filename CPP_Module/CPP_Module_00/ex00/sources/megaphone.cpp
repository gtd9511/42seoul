/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:37:30 by sanghan           #+#    #+#             */
/*   Updated: 2023/02/15 18:32:29 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char *argv[])
{
	int	j;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			j = 0;
			while (argv[i][j] != '\0')
			{
				if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
					argv[i][j] -= 32;
				std::cout << argv[i][j];
				j++;
			}
		}
	}
	std::cout << std::endl;
}
