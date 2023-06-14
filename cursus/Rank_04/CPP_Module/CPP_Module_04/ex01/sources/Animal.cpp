/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:35:08 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/23 20:56:49 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal(void): _type("Animal")
{
	std::cout << "[Animal Class] " << this->_type << " Constructor called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "[Animal Class] " << this->_type << " Destructor called" << std::endl;
}

Animal::Animal(const Animal& obj)
{
	if (this == &obj)
		return ;
	std::cout << "[Animal Class] " << this->_type << " Copy Constructor called" << std::endl;
	*this = obj;
}

Animal& Animal::operator=(const Animal&  obj)
{
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "[Animal Class] " << this->_type << " : (makes some noise)" << std::endl;
}