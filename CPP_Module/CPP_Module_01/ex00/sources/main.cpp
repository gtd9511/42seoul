/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:03:36 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/08 17:48:15 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie A("Alex");
	Zombie *B = new Zombie("Beckham");

	randomChump("Chalri");
	
	A.announce();
	B->announce();
	delete B;
	return (0);
}
