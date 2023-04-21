/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:57:53 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/23 16:13:09 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria*	_memory[4];

	public:
		MateriaSource(void);
		virtual ~MateriaSource(void);
		MateriaSource(const MateriaSource& obj);
		MateriaSource& operator=(const MateriaSource& obj);

		void	learnMateria(AMateria* m);
		AMateria*	createMateria(std::string const & type);
		AMateria* getMateria(int idx) const;
};

#endif
