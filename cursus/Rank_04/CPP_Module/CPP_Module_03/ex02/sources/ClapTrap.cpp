/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:48:14 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/20 20:02:52 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("default"), _hit_point(10), _energy_point(10), _attack_damage(0)
{
	std::cout << "ClapTrap " << this->_name << " is constructed" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->_name << " is destrcuted" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit_point(10), _energy_point(10), _attack_damage(0)
{
	std::cout << "ClapTrap " << this->_name << " is constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj): _name(obj._name), _hit_point(obj._hit_point), _energy_point(obj._energy_point), _attack_damage(obj._attack_damage)
{
	std::cout << "ClapTrap " << this->_name << " is copied" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	std::string	old_name;

	old_name = this->_name;
	this->_name = obj._name;
	this->_hit_point = obj._hit_point;
	this->_energy_point = obj._energy_point;
	this->_attack_damage = obj._attack_damage;

	std::cout << "ClapTrap " << old_name << " is operated (=) " << obj._name << std::endl;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (!this->_hit_point || !this->_energy_point)
		std::cout << "ClapTrap " << this->_name << " can't do anything." << std::endl;
	else
	{
		this->_energy_point--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_point > amount)
	{
		this->_hit_point -= amount;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage! ";
		std::cout << "Now, ClapTrap " << this->_name << " has " << this->_hit_point <<  " Hit_Point." << std::endl;
	}
	else
	{
		this->_hit_point = 0;
		std::cout << "ClapTrap " << this->_name << " dead!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->_hit_point || !this->_energy_point)
		std::cout << "ClapTrap " << this->_name << " can't do anything." << std::endl;
	else
	{
		this->_energy_point--;
		this->_hit_point += amount;
		std::cout << "ClapTrap " << this->_name << " repaired " << amount << " Hit_Point! ";
		std::cout << "Now, ClapTrap " << this->_name << " has " << this->_hit_point <<  " Hit_Point." << std::endl;
	}
}
