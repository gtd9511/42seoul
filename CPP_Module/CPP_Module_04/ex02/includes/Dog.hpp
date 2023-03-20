/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:35:03 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/20 20:55:52 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog(void);
		virtual ~Dog(void);
		Dog(const Dog& obj);
		Dog& operator=(const Dog& obj);

		virtual void	makeSound(void) const;
};

#endif
