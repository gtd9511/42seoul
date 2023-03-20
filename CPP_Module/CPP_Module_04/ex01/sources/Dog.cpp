/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:35:10 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/20 21:32:01 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog(void): Animal()
{
	this->_type = "Dog";
	std::cout << "Dog Class " << this->_type << " Constructor called" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog Class " << this->_type << " Destructor called" << std::endl;
}

Dog::Dog(const Dog& obj): Animal()
{
	if (this != &obj)
		this->_type = obj._type;
	std::cout << "Dog Class " << this->_type << " Copy Consturctor called" << std::endl;
}

Dog& Dog::operator=(const Dog& obj)
{
	if (this != &obj)
		this->_type = obj._type;
	std::cout << "Cat Class " << this->_type << " Operator(=) called " << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog Class " << this->_type << " : Woof! Woof!" << std::endl;
}

