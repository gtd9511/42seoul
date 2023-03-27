/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:51:58 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/27 20:05:00 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

Intern::Intern(void)
{

}

Intern::~Intern(void)
{

}

Intern::Intern(const Intern& obj)
{
	if (this == &obj)
		return ;
	*this = obj;
}

Intern& Intern::operator=(const Intern& obj)
{
	(void)obj;
	return (*this);
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	std::string types[3] = {"shrubbery creation", "robotomy request", "presidential pradon"};
	std::string findform;

	findform = name;
	for (int i = 0; i < 3; i++)
	{
	}
}

