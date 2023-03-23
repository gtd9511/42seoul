/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:58:00 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/22 19:14:11 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource(void):_idx(0)
{
	for (int i = 0; i < 4; i++)
		this->_skill[i] = NULL;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_skill[i])
			delete this->_skill[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource& obj): _idx(obj._idx)
{
	if (this == &obj)
		return ;
	*this = obj;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj)
{
	if (this != &obj)
	{
		this->_idx = obj._idx;
	}
}

void	MateriaSource::learnMateria(AMateria* obj)
{}

AMateria*	MateriaSource::createMateria(std::string const & tpye)
{}


AMateria.hpp
Cure.hpp
Ice.hpp
-ICharacter.hpp
-IMateriaSource.hpp
Character.hpp
MateriaSource.hpp

AMateria.cpp
Cure.cpp
Ice.cpp
Character.cpp
MateriaSource.cpp
main.cpp
Makefile
