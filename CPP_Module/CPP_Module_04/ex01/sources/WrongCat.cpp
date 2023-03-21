/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:35:14 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/21 13:26:17 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "[WrongCat Class] " << this->_type << " Constructor called" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "[WrongCat Class] " << this->_type << " Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj)
{
		if (this != &obj)
		this->_type = obj._type;
	std::cout << "[WrongCat Class] " << this->_type << " Copy Constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
	if (this != &obj)
		this->_type = obj._type;
	std::cout << "[WrongCat Class] " << this->_type << " Operator(=) called" << std::endl;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "[WrongCat Class] " << this->_type << " : meow.. meow.." << std::endl;
}

