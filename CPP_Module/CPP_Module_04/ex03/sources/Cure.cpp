/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:57:56 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/22 16:22:52 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"
#include "../includes/Character.hpp"

Cure::Cure(void):AMateria("Cure")
{
}

Cure::~Cure(void)
{
}

Cure::Cure(const Cure& obj):AMateria(obj)
{
	if (this == &obj)
		return;
	*this = obj;
}

Cure& Cure::operator=(const Cure& obj)
{
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}

AMateria*	Cure::clone() const
{
	return (new Cure());
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
