/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:05:09 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/20 20:01:49 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap(), FragTrap(), ScavTrap()
{
	this->_hit_point = 100;
	this->_energy_point = 50;
	this->_attack_damage = 30;
	std::cout << "DiamondTrap " << this->_name << " is constructed" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->_name << " is destructed" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), _name(name)
{
	this->_hit_point = 100;
	this->_energy_point = 50;
	this->_attack_damage = 30;
	std::cout << "DiamondTrap " << this->_name << " is constructed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj): ClapTrap(obj._name + "_clap_name"), _name(obj._name)
{
	this->_hit_point = obj._hit_point;
	this->_energy_point = obj._energy_point;
	this->_attack_damage = obj._attack_damage;
	std::cout << "DiamondTrap " << this->_name << " is copied" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
{
	std::string	old_name;

	old_name = this->_name;
	this->_name = obj._name;
	ClapTrap::_name = _name + "_clap_name";
	this->_hit_point = obj._hit_point;
	this->_energy_point = obj._energy_point;
	this->_attack_damage = obj._attack_damage;

	std::cout << "ScavTrap " << old_name << " is operated (=) " << obj._name << std::endl;
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap " << this->_name << " : Who... Am... I...? Maybe... " << this->_name << " and My parent is " << ClapTrap::_name << "...?" << std::endl;
}
