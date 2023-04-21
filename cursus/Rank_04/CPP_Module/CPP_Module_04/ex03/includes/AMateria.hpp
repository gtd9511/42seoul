/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:07:00 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/21 20:26:51 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include <string>

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria(void);
		virtual ~AMateria(void);
		AMateria(const AMateria& obj);
		AMateria& operator=(const AMateria& obj);

		AMateria(std::string const & type);

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
