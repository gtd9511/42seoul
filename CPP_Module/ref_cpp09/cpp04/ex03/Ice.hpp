#pragma once
#ifndef Ice_HPP
#define Ice_HPP
#include "AMateria.hpp"

class Ice : public AMateria
{
private:
	
public:
	Ice();
	Ice(const Ice &copy);
	Ice &operator=(const Ice &copy);
	~Ice();

	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
};

#endif // Ice_HPP