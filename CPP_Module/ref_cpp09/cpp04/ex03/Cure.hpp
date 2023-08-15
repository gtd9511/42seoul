#pragma once
#ifndef Cure_HPP
#define Cure_HPP


#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure &copy);
	Cure &operator=(const Cure &copy);
	~Cure();

	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
};

#endif // Cure_HPP