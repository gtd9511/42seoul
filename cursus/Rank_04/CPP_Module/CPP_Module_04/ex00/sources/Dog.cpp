/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:35:10 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/21 19:51:10 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog(void): Animal()
{
	this->_type = "Dog";
	std::cout << "[Dog Class] " << this->_type << " Constructor called" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "[Dog Class] " << this->_type << " Destructor called" << std::endl;
}

Dog::Dog(const Dog& obj): Animal(obj)
{
	if (this == &obj)
		return ;
	std::cout << "[Dog Class] " << this->_type << " Copy Consturctor called" << std::endl;
	*this = obj;
}

Dog& Dog::operator=(const Dog& obj)
{
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "[Dog Class] " << this->_type << " : Woof! Woof!" << std::endl;
}

