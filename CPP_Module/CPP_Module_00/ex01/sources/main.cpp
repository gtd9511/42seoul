/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:13:44 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/03 16:25:15 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook phonebook;
	std::string	cmd;

	while (1)
	{
		std::cout << "Enter command : " << std::endl;
		std::cin >> cmd;
		if (cmd == "ADD")
		{
			phonebook.add();
			//phonebook.add();
		}
		else if (cmd == "SEARCH")
		{
			phonebook.search();
			//phonebook.serach();
		}
		else if (cmd == "EXIT" || std::cin.eof() == true)
			break;
		else
			std::cout << "Invail command" << std::endl;
	}
	return (0);
}
