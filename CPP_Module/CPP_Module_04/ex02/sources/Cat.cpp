/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:35:09 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/20 21:41:24 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat(void): Animal()
{
	this->_type = "Cat";
	std::cout << "Cat Class " << this->_type << " Constructor called" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat Class " << this->_type << " Destructor called" << std::endl;
}

Cat::Cat(const Cat& obj): Animal()
{
	if (this != &obj)
		this->_type = obj._type;
	std::cout << "Cat Class " << this->_type << " Copy Constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& obj)
{
	if (this != &obj)
		this->_type = obj._type;
	std::cout << "Cat Class " << this->_type << " Operator(=) called" << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat Class " << this->_type << " : Meow~ Meow~" << std::endl;
}
