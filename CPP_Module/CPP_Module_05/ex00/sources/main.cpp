/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:46:32 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/25 15:43:19 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include <exception>

int main()
{
	Bureaucrat *a = new Bureaucrat("A", 2);
	try
	{
		std::cout << "1: " << *a << std::endl;
		a->increment();
		std::cout << "2: " << *a << std::endl;
		a->increment();
		std::cout << "3: " << *a << std::endl;
		a->increment();
		std::cout << "4: " << *a << std::endl;
		a->increment();
		std::cout << "4: " << *a << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "A Grade [" << *a << "]" << std::endl;
	delete a;

	std::cout << std::endl;

	Bureaucrat *b = new Bureaucrat("B", 10);
	try
	{
		std::cout << "1: " << *b << std::endl;
		b->increment();
		std::cout << "2: " << *b << std::endl;
		b->increment();
		std::cout << "3: " << *b << std::endl;
		b->increment();
		std::cout << "4: " << *b << std::endl;
		b->increment();
		std::cout << "5: " << *b << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "b Grade [" << *b << "]" << std::endl;
	delete b;

	std::cout << std::endl;

	Bureaucrat *c = new Bureaucrat("C", 145);
	try
	{
		std::cout << "1: " << *c << std::endl;
		c->decrement();
		std::cout << "2: " << *c << std::endl;
		c->decrement();
		std::cout << "3: " << *c << std::endl;
		c->decrement();
		std::cout << "4: " << *c << std::endl;
		c->decrement();
		std::cout << "5: " << *c << std::endl;
		c->decrement();
		std::cout << "6: " << *c << std::endl;
		c->decrement();
		std::cout << "7: " << *c << std::endl;
		c->decrement();
		std::cout << "8: " << *c << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "C Grade [" << *c << "]" << std::endl;

	Bureaucrat d(*c);
	try {
		d.decrement();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	delete c;

	std::cout << std::endl;

	try
	{
		Bureaucrat yudo("Yundo", 151);
		std::cout << "HELLO WORLD!!!" << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat yudo("Yundo", -1);
		std::cout << "HELLO WORLD!!!" << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
