/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:49:16 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/29 17:14:11 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>

class Base
{
	public:
		virtual ~Base(void);
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base * generate(void);

void identify(Base* p);

void identify(Base& p);

#endif


