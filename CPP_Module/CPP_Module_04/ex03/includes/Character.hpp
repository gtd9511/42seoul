/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:57:48 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/22 14:45:09 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARCATER_HPP
# define CHARCATER_HPP

#include "ICharacter.hpp"

class AMateria;

class Character: public ICharacter
{
	private:
		AMateria*	_inventory[4];
		std::string	_name;
	public:
		Character(void);
		virtual ~Character(void);
		Character(const Character& obj);
		Character& operator=(const Character& obj);
		Character(std::string name);

		std::string const & getName() const;
		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);

};

#endif
