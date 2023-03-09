/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:04:23 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/09 17:33:52 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie(void): name_("(default)")
{
	//this->name_ = "(default)";
	std::cout << this->name_ << " is constructed" << std::endl;
}

Zombie::Zombie(std::string name): name_(name)
{
	//this->name_ = name;
	std::cout << this->name_ << " is constructed" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name_ << " is deconstructed" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << this->name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name_ = name;
}
