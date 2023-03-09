/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:06:18 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/09 17:10:37 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
	std::string	name_;
	Weapon		&weapon_;

public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);

	void	attack(void);
};

#endif
