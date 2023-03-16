/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:11:06 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/16 21:02:57 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		FragTrap(void);
		~FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap& obj);
		FragTrap& operator=(const FragTrap& obj);

		void	highFivesGuys(void);
};

#endif
