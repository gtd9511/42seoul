/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook2.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:05:38 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/07 15:50:08 by sanghan          ###   ########.fr       */
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
	std::string	input;

	std::cout << "Enter Contact Information" << std::endl
		<< " > First name : ";
	input = getContact();
	contact[index].setFirstname(input);

	std::cout << " > Last name : ";
	input = getContact();
	contact[index].setLastname(input);

	std::cout << " > Nickname: ";
	input = getContact();
	contact[index].setNickname(input);

	std::cout << " > Phone number: ";
	input = getContact();
	contact[index].setPhonenumber(input);

	std::cout << " > Darkest secret: ";
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
		//if (std::cin.eof() == true)
		//	exit(0);
		if (input.size() > 0)
			break;
		else
			std::cout << "Invalid Form." << std::endl
				<< "Please Enter Again : ";
	}
	return (input);
}

void	PhoneBook::search(void)
{
	std::string	input;

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

	while (1)
	{
		std::cout << "Enter The Index : ";
		std::getline(std::cin, input);

		if (std::cin.eof() == true)
			exit(0);
		if (input.size() == 0 || input < "1" || input > "8" || std::stoi(input) > index)
		{
			std::cin.clear();
			std::cout << "Invalid Index" << std::endl
				<< "Enter Again";
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

std::string PhoneBook::checkWidth(std::string column)
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


/*

std::string	PhoneBook::add_spaces(int n)
{
	std::string	str;

	while (n-- > 0)
		str.append(" ");
	return (str);
}

std::string	PhoneBook::width_make(std::string str, unsigned long max)
{
	if (str.size() > max)
	{
		str.resize(max);
		str[str.size() - 1] = '.';
	}
	return (str);
}

int	PhoneBook::search_ui(Contact contacts[8])
{
	char	c;
	int		i;
	std::string	str;

	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	c = '0';
	i = 0;
	while (++c <= '8')
	{
		if (contacts[c - 1 - '0'].get_fname().size() && ++i)
		{
			str = c;
			str = width_make(str, 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			str = width_make(contacts[c - 1  - '0'].get_fname(), 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			str = width_make(contacts[c - 1 - '0'].get_lname(), 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			str = width_make(contacts[c - 1 - '0'].get_nick(), 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			std::cout << "|" << std::endl;
		}
	}
	std::cout << " ___________________________________________ " << std::endl;
	return (i);
}

void	PhoneBook::add(void)
{
	std::string	str;

	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a first name: ";
		if (std::getline(std::cin, str) && str != "")
			this->contacts_[this->idx_ % 8].set_fname(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a last name: ";
		if (std::getline(std::cin, str) && str != "")
			this->contacts_[this->idx_ % 8].set_lname(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a nick name: ";
		if (std::getline(std::cin, str) && str != "")
			this->contacts_[this->idx_ % 8].set_nick(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a phone number: ";
		if (std::getline(std::cin, str) && str != "")
			this->contacts_[this->idx_ % 8].set_pnum(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a darkest secret: ";
		if (std::getline(std::cin, str) && str != "")
			this->contacts_[this->idx_ % 8].set_secret(str);
	}
	this->idx_++;
}

void	PhoneBook::print(Contact contact)
{
	if (!contact.get_fname().size())
	{
		std::cout << "Invaild contact instance." << std::endl;
	}
	std::cout << "First Name: " << contact.get_fname() << std::endl;
	std::cout << "Last Name: " << contact.get_lname() << std::endl;
	std::cout << "Nickname: " << contact.get_nick() << std::endl;
	std::cout << "Phone Number: " << contact.get_pnum() << std::endl;
	std::cout << "Darkest Secret: " << contact.get_secret() << std::endl;
}

Contact	PhoneBook::get_contact(int idx)
{
	return (this->contacts_[idx % 8]);
}

void	PhoneBook::search(void)
{
	std::string	str;

	if (!search_ui(this->contacts_))
	{
		std::cout << std::endl << "There is no contact." << std::endl;
		return ;
	}
	while (!std::cin.eof())
	{
		std::cout << "Select an index: ";
		if (std::getline(std::cin, str) && str != "")
		{
			if (str.size() == 1 && str[0] >= '1' && str[0] <= '8' && \
			get_contact(str[0] - 1 - '0').get_fname().size())
				break ;
		}
		if (str != "")
			std::cout << "Invaild index." << std::endl;
	}
	if (!std::cin.eof())
		this->print(get_contact(str[0] - 1 - '0'));
}
*/
