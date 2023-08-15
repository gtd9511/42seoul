#include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure &copy) : AMateria("cure")
{
	this->type = copy.type;	
}

Cure &Cure::operator=(const Cure &copy)
{
	std::cout << "Cure::operator=(const Cure &copy)" << std::endl;
	if (this != &copy)
	{
		this->type = copy.type;
	}
	return *this;
}

Cure::~Cure()
{
	std::cout << "~Cure()"<< std::endl;
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds * " << std::endl;
}

AMateria *Cure::clone() const
{	
	return new Cure();
}