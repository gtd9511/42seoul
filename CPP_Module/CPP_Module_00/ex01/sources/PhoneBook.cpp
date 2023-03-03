/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:05:38 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/03 16:24:03 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "Created PhoneBook" << std::endl;
	this->index = 0;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Destroyed PhoneBook" << std::endl;
}

void	PhoneBook::add(void)
{
	std::string	input;

	std::cout << "Enter First name : ";
	input = getContactInfo();
	contact[index].setFirstname(input);

	std::cout << "Enter Last name : ";
	input = getContactInfo();
	contact[index].setLastname(input);

	std::cout << "Enter Nickname: ";
	input = getContactInfo();
	contact[index].setNickname(input);

	std::cout << "Enter Phone number: ";
	input = getContactInfo();
	contact[index].setPhonenumber(input);

	std::cout << "Enter Darkest secret: ";
	input = getContactInfo();
	contact[index].setDarkestsecret(input);

	this->index++;
}

std::string	PhoneBook::getContactInfo(void)
{
	std::string	input;

	while(1)
	{
		if (!input.empty())
			input.clear();
		std::getline(std::cin, input);
		if (std::cin.eof() == true)
			exit(0);
		else if (input.size() > 0)
			break;
		else
			std::cout << "Enter Again : ";
	}
	return (input);
}

void	PhoneBook::search(void)
{
	std::string	input;

	if (this->index == 0)
	{
		std::cout << "Empty Contact" << std::endl;
		return;
	}

	std::cout << "|" << std::setw(10) << "Index"
		<< "|" << std::setw(10) << "First name"
		<< "|" << std::setw(10) << "Last name"
		<< "|" << std::setw(10) << "Nickname"
		<< "|" << std::endl;

	for (int i = 0;i < index; i++)
	{
		std::cout << "|" << std::setw(10) << i + 1
			<< "|" << std::setw(10) << checkColumn(contact[i].getFirstname())
			<< "|" << std::setw(10) << checkColumn(contact[i].getLastname())
			<< "|" << std::setw(10) << checkColumn(contact[i].getNickname())
			<< "|" << std::endl;

	}

	while (1)
	{
		std::cout << "Enter the index : ";
		std::getline(std::cin, input);

		if (std::cin.eof() == true)
			exit(0);
		if (input.size() == 0 || input < "1" || input > "8" || std::stoi(input) > index)
		{
			std::cin.clear();
			std::cout << "Invalid index" << std::endl;
		}
		else
			break;
	}

	std::cout << "FirstName: " << contact[std::stoi(input) - 1].getFirstname() << std::endl
		<< "LastName: " << contact[std::stoi(input) - 1].getLastname() << std::endl
		<< "Nickname: " << contact[std::stoi(input) - 1].getNickname() << std::endl
		<< "PhoneNumber: " << contact[std::stoi(input) - 1].getPhonenumber() << std::endl
		<< "DarkestSecret: " << contact[std::stoi(input) - 1].getDarkestsecret() << std::endl;

}

std::string PhoneBook::checkColumn(std::string column)
{
		if (column.size() > 10)
		column = column.substr(0, 9) + ".";
	return column;
}
