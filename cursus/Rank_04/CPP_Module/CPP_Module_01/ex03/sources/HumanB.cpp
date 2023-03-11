/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:06:25 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/11 14:52:39 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name): name_(name), weapon_(NULL)
{
	std::cout << this->name_ << " is constructed" << std::endl;
	std::cout << this->name_ << " isn't armed " << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << this->name_ << " is deconstructed" << std::endl;
}

void	HumanB::attack(void)
{
	if (this->weapon_ == NULL)
		std::cout << this->name_ << " isn't amred" << std::endl;
	else
		std::cout << this->name_ << " attacks with his " << this->weapon_->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon_ = &weapon;
}
