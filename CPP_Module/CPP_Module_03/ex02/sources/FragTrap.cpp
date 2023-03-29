/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:54:22 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/29 13:50:21 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
	this->_hit_point = 100;
	this->_energy_point = 100;
	this->_attack_damage = 30;
	std::cout << "FragTrap " << this->_name << " is constructed" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->_name << " is destructed" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_hit_point = 100;
	this->_energy_point = 100;
	this->_attack_damage = 30;
	std::cout << "FragTrap " << this->_name << " is constructed" << std::endl;
}

FragTrap::FragTrap(const FragTrap& obj): ClapTrap(obj._name)
{
	this->_hit_point = obj._hit_point;
	this->_energy_point = obj._energy_point;
	this->_attack_damage = obj._attack_damage;
	std::cout << "FragTrap " << this->_name << " is copied" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
	std::string	old_name;

	old_name = this->_name;
	this->_name = obj._name;
	this->_hit_point = obj._hit_point;
	this->_energy_point = obj._energy_point;
	this->_attack_damage = obj._attack_damage;

	std::cout << "FragTrap " << old_name << " is operated (=) " << obj._name << std::endl;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	if (!this->_hit_point || !this->_energy_point)
		std::cout << "FragTrap " << this->_name << " can't do anything." << std::endl;
	else
	{
		this->_energy_point--;
		std::cout << "FragTrap " << this->_name << " high five!" << std::endl;
	}
}
