/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:04:23 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/08 20:28:47 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	this->name = "(default)";
	std::cout << this->name << " is constructed" << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << this->name << " is constructed" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name << " is deconstructed" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}
