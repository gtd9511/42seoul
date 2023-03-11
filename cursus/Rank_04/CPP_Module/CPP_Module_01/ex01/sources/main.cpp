/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:04:14 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/11 16:04:59 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int	main()
{
	int n;

	n = 10;
	Zombie	*horde = zombieHorde(n, "zombiename");
	for (int i = 0; i < n; i++)
		horde[i].announce();
	delete []horde;
	return (0);
}
