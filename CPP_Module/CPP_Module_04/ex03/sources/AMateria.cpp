/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:22:12 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/22 18:20:12 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

AMateria::AMateria(void): _type("default")
{
}

AMateria::~AMateria(void)
{
}

AMateria::AMateria(const AMateria& obj)
{
	if (this == &obj)
		return ;
	*this = obj;
}

AMateria& AMateria::operator=(const AMateria& obj)
{
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}

AMateria::AMateria(std::string const & type): _type(type)
{
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "dskf;lasdkfl;dsakf;lkdsa;flkasd" << std::endl;
	//(void)target;
}
