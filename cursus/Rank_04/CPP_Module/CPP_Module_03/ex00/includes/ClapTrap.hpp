/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:27:29 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/16 14:46:09 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	private:
		std::string	_name;
		unsigned int	_hit_point;
		unsigned int	_energy_point;
		unsigned int	_attack_damage;

	public:
		ClapTrap(void);
		~ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& obj);
		ClapTrap& operator=(const ClapTrap& obj);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
