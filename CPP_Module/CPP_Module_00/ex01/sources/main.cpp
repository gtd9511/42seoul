/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:13:44 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/09 20:14:16 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"
#include <csignal>

void	sig_handler(int signum)
{
	(void)signum;
}

int	main(void)
{
	PhoneBook phonebook;
	std::string	cmd;

	signal(SIGTSTP, SIG_IGN);
	while (1)
	{
		std::cout << "Enter command [ ADD | SEARCH | EXIT ] : " << std::endl;
		if (!cmd.empty())
			cmd.clear();
		std::cin >> cmd;
		std::cin.ignore();
		if (cmd == "ADD" || cmd == "add")
			phonebook.add();
		else if (cmd == "SEARCH" || cmd == "search")
			phonebook.search();
		else if (cmd == "EXIT" || cmd == "exit" || std::cin.eof() == true)
			break;
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}
