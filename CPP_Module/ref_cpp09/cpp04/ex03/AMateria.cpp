#include "AMateria.hpp"

AMateria::AMateria()
{

}

AMateria::AMateria(std::string const & type) : type(type)
{
}

AMateria::AMateria(const AMateria &copy)
{
	this->type = copy.type;	
}

AMateria &AMateria::operator=(const AMateria &copy)
{
	if(this != &copy)
	{
		this->type = copy.type;
	}
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "~AMateria()"<< std::endl;
}

std::string const &AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "AMateria use(ICharacter &target)" << " " << target.getName() << std::endl;
}