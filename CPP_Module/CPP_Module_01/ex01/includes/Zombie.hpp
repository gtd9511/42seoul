/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:04:19 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/10 19:33:49 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <sstream>

class Zombie
{
	private:
		std::string	name_;
	
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
	
		void	announce( void );
		void	setName(std::string name);
};

Zombie	*zombieHorde( int N, std::string name );

#endif
