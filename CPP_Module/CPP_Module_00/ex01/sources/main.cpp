/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:13:44 by sanghan           #+#    #+#             */
/*   Updated: 2023/02/20 13:29:47 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	cmd;

	while (1)
	{
		std::cout << "Enter command : " << std::endl;
		std::cin >> cmd;
		if (cmd == "ADD")
		{
		}
		else if (cmd == "SEARCH")
		{
		}
		else if (cmd == "EXIT")
			break;
		else
			std::cout << "Invail command" << std::endl;
	}
	return (0);
}
