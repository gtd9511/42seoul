/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:27:28 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/15 20:33:33 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("default"), _hitpoint(10), _energypoint(10), _attackdamage(0)
{
	std::cout << "ClapTrap " << this->_name << " is constructed" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->_name << "is deconstructed" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitpoint(10), _energypoint(10), _attackdamage(0)
{
	std::cout << "ClapTrap " << this->_name << " is constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj): _name(obj._name), _hitpoint(obj._hitpoint), _energypoint(obj._energypoint), _attackdamage(obj._attackdamage)
{
	std::cout << "ClapTrap " << this->_name << " is copied" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	this->_name = obj._name;


}

//unsigned int getDamage(void) const;
void	ClapTrap::attack(const std::string& target)
{}

void	ClapTrap::takeDamage(unsigned int amount)
{}

void	ClapTrap::beRepaired(unsigned int amount)
{}
