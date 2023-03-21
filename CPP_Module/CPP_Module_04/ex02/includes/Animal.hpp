/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:22:03 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/21 14:54:11 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string	_type;

	public:
		Animal(void);
		virtual ~Animal(void);
		Animal(const Animal& obj);
		Animal& operator=(const Animal&  obj);

		std::string	getType(void) const;
		virtual void	makeSound(void) const = 0;
};

#endif
