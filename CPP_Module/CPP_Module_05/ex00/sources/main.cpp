/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:46:32 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/24 21:49:03 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

/*int main()
{
	try
	{
		try
		{
			Bureaucrat test("test", 200);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl;
		Bureaucrat a("a", 150);
		Bureaucrat b("b", 1);
		Bureaucrat c("c", 75);
		Bureaucrat temp = c;

		std::cout << std::endl;
		temp = b;
		std::cout << "D's Grade = " << temp << std::endl;

		std::cout << std::endl;

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;

		a.increment();
		//b.increment();
		b.decrement();
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}*/
int main() {


	Bureaucrat *A = new Bureaucrat("A", 2);
	try {
		std::cout << "1: " << *A << std::endl;
		A->increment();
		std::cout << "2: " << *A << std::endl;
		A->increment();
		std::cout << "3: " << *A << std::endl;
		A->increment();
		std::cout << "4: " << *A << std::endl;
		A->increment();
		std::cout << "4: " << *A << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	delete A;

	std::cout << std::endl;

	Bureaucrat *B = new Bureaucrat("B", 10);
	try {
		std::cout << "1: " << *B << std::endl;
		B->increment();
		std::cout << "2: " << *B << std::endl;
		B->increment();
		std::cout << "3: " << *B << std::endl;
		B->increment();
		std::cout << "4: " << *B << std::endl;
		B->increment();
		std::cout << "5: " << *B << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	delete B;

	std::cout << std::endl;

	Bureaucrat *C = new Bureaucrat("C", 145);
	try {
		std::cout << "1: " << *C << std::endl;
		C->decrement();
		std::cout << "2: " << *C << std::endl;
		C->decrement();
		std::cout << "3: " << *C << std::endl;
		C->decrement();
		std::cout << "4: " << *C << std::endl;
		C->decrement();
		std::cout << "5: " << *C << std::endl;
		C->decrement();
		std::cout << "6: " << *C << std::endl;
		C->decrement();
		std::cout << "7: " << *C << std::endl;
		C->decrement();
		std::cout << "8: " << *C << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	delete C;

	std::cout << std::endl;

	try {
		Bureaucrat yudo("Yundo", 151);
		std::cout << "HELLO WORLD!!!" << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Bureaucrat yudo("Yundo", -1);
		std::cout << "HELLO WORLD!!!" << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	system("leaks a.out");
	return 0;
}
