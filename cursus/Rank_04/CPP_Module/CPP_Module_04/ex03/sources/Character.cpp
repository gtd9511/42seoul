/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:57:54 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/23 17:06:33 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character(void): _name("default")
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete _inventory[i];
	}
}

Character::Character(const Character& obj)
{
	if (this == &obj)
		return ;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	*this = obj;
}

Character& Character::operator=(const Character& obj)
{
	if (this != &obj)
	{
		this->_name = obj._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i] != NULL)
				delete this->_inventory[i];
			this->_inventory[i] = obj._inventory[i]->clone();
		}
	}
	return (*this);
}

Character::Character(std::string name): _name(name)
{
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
	}
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL && m != NULL)
		{
			this->_inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 4 && idx >= 0 && _inventory[idx] != NULL)
		this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && idx >= 0 && _inventory[idx] != NULL)
	{
		this->_inventory[idx]->use(target);
	}
}
