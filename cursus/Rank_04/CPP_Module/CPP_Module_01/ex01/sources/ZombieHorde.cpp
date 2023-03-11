/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:04:26 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/09 17:33:49 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie	*zombieHorde( int N, std::string name )
{
	std::stringstream	ss;

	Zombie	*horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		ss.str(std::string());
		ss << i;
		horde[i].setName(name + ss.str());
	}
	return (horde);
}
