/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:05:05 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/20 19:38:29 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
	private:
		std::string	_name;
	public:
		DiamondTrap(void);
		virtual~DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& obj);
		DiamondTrap& operator=(const DiamondTrap& obj);

		void	whoAmI(void);
};

#endif
