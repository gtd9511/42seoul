/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:35:01 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/20 14:10:39 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat
{
	private:

	public:
		Cat(void);
		virtual ~Cat(void);
		Cat(const Cat& obj);
		Cat& operator=(const Cat& obj);
};

#endif
