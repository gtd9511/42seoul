/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:05:11 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/17 14:43:52 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap a("A");
	FragTrap b("B");
	ClapTrap c("C");

	std::cout << std::endl;

	a.attack("B");
	b.takeDamage(30);
	a.attack("C");
	c.takeDamage(30);
	b.attack("A");
	a.takeDamage(30);
	a.beRepaired(10);
	std::cout << std::endl;

	a.highFivesGuys();
	a.guardGate();
	a.whoAmI();

	std::cout << std::endl;

	return (0);
}
