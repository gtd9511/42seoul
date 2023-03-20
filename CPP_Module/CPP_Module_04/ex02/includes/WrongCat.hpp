/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:35:06 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/20 21:40:05 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "../includes/WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat(void);
		virtual ~WrongCat(void);
		WrongCat(const WrongCat& obj);
		WrongCat& operator=(const WrongCat& obj);

		virtual void	makeSound(void) const;
};

#endif
