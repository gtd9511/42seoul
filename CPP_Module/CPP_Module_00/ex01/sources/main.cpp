/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:13:44 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/06 17:29:49 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook phonebook;
	std::string	cmd;

	while (1)
	{
		std::cout << "Enter command [ ADD | SEARCH | EXIT ] : " << std::endl;
		std::cin >> cmd;
		if (cmd == "ADD")
			phonebook.add();
		else if (cmd == "SEARCH")
			phonebook.search();
		else if (cmd == "EXIT" || std::cin.eof() == true)
			break;
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}
