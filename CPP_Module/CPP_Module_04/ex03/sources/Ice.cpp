/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:57:57 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/22 16:22:25 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"
#include "../includes/Character.hpp"

Ice::Ice(void):AMateria("Ice")
{
}

Ice::~Ice(void)
{
}

Ice::Ice(const Ice& obj):AMateria(obj)
{
	if (this == &obj)
		return;
	*this = obj;
}

Ice& Ice::operator=(const Ice& obj)
{
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}

AMateria*	Ice::clone() const
{
	return (new Ice());
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
