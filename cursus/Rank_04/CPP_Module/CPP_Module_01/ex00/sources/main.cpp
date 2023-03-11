/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:03:36 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/09 17:34:02 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

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
