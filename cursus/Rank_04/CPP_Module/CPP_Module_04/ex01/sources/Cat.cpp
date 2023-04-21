/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:35:09 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/21 19:52:33 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat(void): Animal()
{
	this->_type = "Cat";
	std::cout << "[Cat Class] " << this->_type << " Constructor called" << std::endl;
	this->brain = new Brain();
}

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << "[Cat Class] " << this->_type << " Destructor called" << std::endl;
	this->brain = NULL;
}

Cat::Cat(const Cat& obj): Animal(obj)
{
	if (this == &obj)
		return ;
	std::cout << "[Cat Class] " << this->_type << " Copy Consturctor called" << std::endl;
	this->brain = NULL;
	*this = obj;
}

Cat& Cat::operator=(const Cat& obj)
{
	if (this != &obj)
	{
		this->_type = obj._type;
		if(this->brain)
			delete this->brain;
		this->brain = new Brain(*obj.brain);
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "[Cat Class] " << this->_type << " : Meow~ Meow~" << std::endl;
}

Brain	*Cat::getBrain(void) const
{
	return (this->brain);
}
