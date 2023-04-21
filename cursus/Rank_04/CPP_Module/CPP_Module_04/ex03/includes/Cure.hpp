/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:57:49 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/22 16:11:39 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure(void);
		virtual ~Cure(void);
		Cure(const Cure& obj);
		Cure& operator=(const Cure& obj);

		AMateria*	clone() const;
		void	use(ICharacter& target);
};

#endif
