/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:09:27 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/28 15:32:15 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"
#include <exception>

int main(void)
{
	Bureaucrat a("Alex", 1);
	Bureaucrat b("Bob", 149);

	Intern somRandomIntern;
	AForm*	rrf;
	try
	{
		rrf = somRandomIntern.makeForm("robotomy request", "stark industry");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}
	try
	{
		b.signForm(*rrf);
		std::cout << *rrf << std::endl;
		b.executeForm(*rrf);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << *rrf << std::endl;
	try
	{
		a.signForm(*rrf);
		std::cout << *rrf << std::endl;
		a.executeForm(*rrf);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}

