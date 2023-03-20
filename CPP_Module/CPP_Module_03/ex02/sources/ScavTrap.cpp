/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:49:34 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/20 20:01:49 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
	this->_hit_point = 100;
	this->_energy_point = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap " << this->_name << " is constructed" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->_name << " is destructed" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_hit_point = 100;
	this->_energy_point = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap " << this->_name << " is constructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj): ClapTrap(obj._name)
{
	this->_hit_point = obj._hit_point;
	this->_energy_point = obj._energy_point;
	this->_attack_damage = obj._attack_damage;
	std::cout << "ScavTrap " << this->_name << " is copied" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
	std::string	old_name;

	old_name = this->_name;
	this->_name = obj._name;
	this->_hit_point = obj._hit_point;
	this->_energy_point = obj._energy_point;
	this->_attack_damage = obj._attack_damage;

	std::cout << "ScavTrap " << old_name << " is operated (=) " << obj._name << std::endl;
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (!this->_hit_point || !this->_energy_point)
		std::cout << "ScavTrap " << this->_name << " can't do anything." << std::endl;
	else
	{
		this->_energy_point--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	}
}

void	ScavTrap::guardGate(void)
{
	if (!this->_hit_point || !this->_energy_point)
		std::cout << "ScavTrap " << this->_name << " can't do anything." << std::endl;
	else
	{
		this->_energy_point--;
		std::cout << "ScavTrap " << this->_name << " has entered gate guard mode!" << std::endl;
	}
}
