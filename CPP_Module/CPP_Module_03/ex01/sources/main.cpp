/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:17:00 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/16 16:08:19 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

int	main(void)
{
	
	ScavTrap a("A");
	ScavTrap b("B");

	std::cout << std::endl;

	a.attack("B");
	b.takeDamage(20);
	b.beRepaired(10);
	std::cout << std::endl;

	b.attack("A");
	a.takeDamage(20);
	a.beRepaired(10);
	std::cout << std::endl;

	a.guardGate();
	std::cout << std::endl;

	return (0);
}
