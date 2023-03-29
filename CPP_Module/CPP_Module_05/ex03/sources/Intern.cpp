/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:51:58 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/29 13:26:10 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include <cstring>

Intern::Intern(void)
{
	f[0] = new ShrubberyCreationForm("");
	f[1] = new RobotomyRequestForm("");
	f[2] = new PresidentialPardonForm("");
}

Intern::~Intern(void)
{
	if (this->f[0])
		delete f[0];
	else if (this->f[1])
		delete f[1];
	else if (this->f[2])
		delete f[2];
}

Intern::Intern(const Intern& obj)
{
	if (this == &obj)
		return ;
	this->f[0] = NULL;
	this->f[1] = NULL;
	this->f[2] = NULL;
	*this = obj;
}

Intern& Intern::operator=(const Intern& obj)
{
	if (this != &obj)
	{
		if (this->f[0])
			delete f[0];
		else if (this->f[1])
			delete f[1];
		else if (this->f[2])
			delete f[2];

		this->f[0] = new ShrubberyCreationForm("");
		this->f[1] = new RobotomyRequestForm("");
		this->f[2] = new PresidentialPardonForm("");
	}
	return (*this);
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	int pos = 0;
	std::string type[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	AForm *rrf;

	for (int i = 0; i < 3; i++)
	{
		if (type[i] == name)
		{
			pos = i + 1;
			break;
		}
	}
	switch (pos)
	{
		case 1:
			delete f[0];
			f[0]= new ShrubberyCreationForm(target);
			rrf = f[0];
			std::cout << "Intern creates " << *f[0] << std::endl;
			break;
		case 2:
			delete f[1];
			f[1] = new RobotomyRequestForm(target);
			rrf = f[1];
			std::cout << "Intern creates " << *f[1] << std::endl;
			break;
		case 3:
			delete f[2];
			f[2] = new PresidentialPardonForm(target);
			rrf = f[2];
			std::cout << "Intern creates " << *f[2] << std::endl;
			break;
		default:
			std::cout << "Invalid Format Name Entered" << std::endl;
			throw WrongForm();
	}
	return (rrf);
}

const char* Intern::WrongForm::what(void) const throw()
{
	return ("Wrong Form Name.");
}
