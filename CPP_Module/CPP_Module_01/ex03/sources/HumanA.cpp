/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:06:20 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/20 20:01:49 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): name_(name), weapon_(weapon)
{
	std::cout << this->name_ << " is constructed" << std::endl;
	std::cout << this->name_ << " is armed with a " << weapon.getType() << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << this->name_ << " is destructed" << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << this->name_ << " attacks with his " << this->weapon_.getType() << std::endl;
}
