/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:14:36 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/29 18:25:32 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"

Base::~Base()
{
}

Base * generate(void)
{
	std::time_t time = std::time(nullptr);
	Base * ret = NULL;

	switch(time % 3)
	{
		case(0):
			ret = new A();
		case(1):
			ret = new B();
		case(2):
			ret = new C();
	}
	return (ret);
}

void identify(Base* p)
{
	
}

void identify(Base& p)
{}

std::time_t	currentTime = std::time(nullptr);

