/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:35:01 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/21 10:15:41 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain	*brain;
	public:
		Cat(void);
		virtual ~Cat(void);
		Cat(const Cat& obj);
		Cat& operator=(const Cat& obj);

		virtual void	makeSound(void) const;
		Brain	*getBrain(void) const;
};

#endif
