/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:09:27 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/28 11:00:13 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat a("Alex", 1);
	Bureaucrat b("Bob", 10);
	Bureaucrat c("Chalrie", 30);
	Bureaucrat d("Daniel", 50);
	Bureaucrat e("Eric", 149);
	std::cout << std::endl;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
	std::cout << std::endl;

	ShrubberyCreationForm red("LEE"); // sign 145 exec 137
	RobotomyRequestForm	green("GON"); // sign 72 exec 45
	PresidentialPardonForm blue("GAM"); // sign 25 exec 5

	std::cout << std::endl;
	std::cout << red;
	std::cout << green;
	std::cout << blue << std:: endl;

	try
	{
		red.beSigned(e);
		e.executeForm(red);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << red;
	std::cout << green;
	std::cout << blue << std:: endl;
	try
	{
		red.beSigned(d);
		d.executeForm(red);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
 	std::cout << std::endl;
	std::cout << red;
	std::cout << green;
	std::cout << blue << std:: endl;
	try
	{
		red.beSigned(e);
		e.executeForm(red);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << red;
	std::cout << green;
	std::cout << blue << std:: endl;
	try
	{
		green.beSigned(d);
		d.executeForm(green);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << red;
	std::cout << green;
	std::cout << blue << std:: endl;
	try
	{
		green.beSigned(c);
		c.executeForm(green);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
 	std::cout << std::endl;
	std::cout << red;
	std::cout << green;
	std::cout << blue << std:: endl;
	try
	{
		blue.beSigned(b);
		b.executeForm(blue);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
 	std::cout << std::endl;
	std::cout << red;
	std::cout << green;
	std::cout << blue << std:: endl;
	try
	{
		blue.beSigned(c);
		c.executeForm(blue);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
 	std::cout << std::endl;
	std::cout << red;
	std::cout << green;
	std::cout << blue << std:: endl;
	try
	{
		blue.beSigned(a);
		a.executeForm(blue);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
 	std::cout << std::endl;
	std::cout << red;
	std::cout << green;
	std::cout << blue << std:: endl;

	return (0);
}

