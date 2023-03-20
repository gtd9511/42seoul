/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:03:42 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/20 20:01:49 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie(std::string name): name_(name)
{
	std::cout << this->name_ << " is constructed" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name_ << " is destructed" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << this->name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
