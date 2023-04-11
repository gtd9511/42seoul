/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:14:36 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/30 20:05:21 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"

Base::~Base() {}

Base * generate(void)
{
	std::time_t time = std::time(nullptr);
	Base * base = NULL;
	switch(time % 3)
	{
		case(0):
			base = new A();
			break;
		case(1):
			base = new B();
			break;
		case(2):
			base = new C();
	}
	return (base);
}

void identify(Base* p)
{
	try
	{
		if (dynamic_cast<A*>(p))
			std::cout << "pointer is A" << std::endl;
		if (dynamic_cast<B*>(p))
			std::cout << "pointer is B" << std::endl;
		if (dynamic_cast<C*>(p))
			std::cout << "pointer is C" << std::endl;
	}
	catch (std::exception&){}

}

void identify(Base& p)
{
	try
	{
		if (dynamic_cast<A*>(&p))
			std::cout << "reference is A" << std::endl;
		if (dynamic_cast<B*>(&p))
			std::cout << "reference is B" << std::endl;
		if (dynamic_cast<C*>(&p))
			std::cout << "reference is C" << std::endl;
	}
	catch (std::exception&){}
}


