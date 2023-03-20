/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:35:12 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/20 21:38:55 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _type("WrongAnimal")
{
	std::cout << "WrongAnimal Class " << this->_type << " Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal Class " << this->_type << " Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
	if (this != &obj)
		this->_type = obj._type;
	std::cout << "WrongAnimal Class " << this->_type << " Copy Constructor called" << std::endl;

}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
	if (this != &obj)
		this->_type = obj._type;
	std::cout << "WrongAnimal Class " << this->_type << " Operator(=) called" << std::endl;
	return (*this);
}

std::string	WrongAnimal::getType(void) const
{
	return (_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal Class " << this->_type << " : (makes some noise)" << std::endl;
}
