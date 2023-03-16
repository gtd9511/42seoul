/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:01:41 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/16 21:02:38 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

int	main(void)
{
	FragTrap a("A");
	FragTrap b("B");

	std::cout << std::endl;

	a.attack("B");
	b.takeDamage(30);
	b.beRepaired(3);
	std::cout << std::endl;

	b.attack("A");
	a.takeDamage(30);
	a.beRepaired(10);
	std::cout << std::endl;

	a.highFivesGuys();
    b.highFivesGuys();
	std::cout << std::endl;

	return (0);
}
