/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook3.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:35:24 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/07 16:11:31 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->index = 0;
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::add(void)
{
	std::string input;

	std::cout << "Enter Contact Information" << std::endl
		<< " 	First name : ";
	input = getContact();
	contact[index].setFirstname(input);

	std::cout << "	Last name : ";
	input = getContact();
	contact[index].setLastname(input);

	std::cout << "	Nickname : ";
	input = getContact();
	contact[index].setNickname(input);

	std::cout << "	Phone number : ";
	input = getContact();
	contact[index].setPhonenumber(input);

	std::cout << "	Darkest secret : ";
	input = getContact();
	contact[index].setDarkestsecret(input);

	this->index++;
}

std::string	PhoneBook::getContact(void)
{
	std::string	input;

	while(1)
	{
		std::getline(std::cin, input);
		if (std::cin.eof() == true)
			exit(0);
		else if (input.size() > 0)
			break;
		else
			std::cout << "Invalid Form." << std::endl << "Please Enter Again :";
	}
	return (input);
}

void	PhoneBook::search(void)
{
	std::string input;

	if (this->index == 0)
	{
		std::cout << "Contact Is Empty" << std::endl;
		return;
	}

	Drawline();

	std::cout << "|" << std::setw(10) << "Index"
		<< "|" << std::setw(10) << "First name"
		<< "|" << std::setw(10) << "Last name"
		<< "|" << std::setw(10) << "Nickname"
		<< "|" << std::endl;

	Drawline();

	for (int i = 0;i < index; i++)
	{
		std::cout << "|" << std::setw(10) << i + 1
			<< "|" << std::setw(10) << checkWidth(contact[i].getFirstname())
			<< "|" << std::setw(10) << checkWidth(contact[i].getLastname())
			<< "|" << std::setw(10) << checkWidth(contact[i].getNickname())
			<< "|" << std::endl;
	}

	Drawline();

	while(1)
	{
		std::cout << "	Enter The Index : ";
		std::getline(std::cin, input);

		if (std::cin.eof() == true)
			exit(0);
		if (input.size() == 0 || input < "1" || input > "8" || std::stoi(input) > index)
		{
			std::cin.clear();
			std::cout << "Invalid Index" << std::endl
				<< "	Enter Again : ";
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

std::string	PhoneBook::checkWidth(std::string column)
{
	if (static_cast<int>(column.size()) > 10)
		return (column.substr(0, 9) + ".");
	else
		return (column);
}

void	PhoneBook::Drawline(void)
{
	std::cout << " ";
	for (int i = 0; i < 43; i++)
		std::cout << "-";
	std::cout << std::endl;
}
