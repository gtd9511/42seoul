/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:58:00 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/23 17:05:33 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->_memory[i] = NULL;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_memory[i] != NULL)
			delete _memory[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource& obj)
{
	if (this == &obj)
		return ;
	for (int i = 0; i < 4; i++)
		this->_memory[i] = NULL;
	*this = obj;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj)
{
	if (this != &obj)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_memory[i] != NULL)
				delete this->_memory[i];
			this->_memory[i] = obj._memory[i]->clone();
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_memory[i] == NULL)
		{
			this->_memory[i] = m;
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_memory[i] != NULL && _memory[i]->getType() == type)
			return (_memory[i]->clone());
	}
	return (NULL);
}
