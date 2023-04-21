/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:57:50 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/22 16:18:47 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice(void);
		virtual ~Ice(void);
		Ice(const Ice& obj);
		Ice& operator=(const Ice& obj);

		AMateria*	clone() const;
		void	use(ICharacter& target);
};

#endif
