#include "WrongCat.hpp"

WrongCat::WrongCat() :WrongAnimal()
{
	std::cout << "WrongCat constructor called.\n";
	this->type = "Dog";
}

WrongCat::WrongCat(const WrongCat& copy)
{
	std::cout << "WrongCat copy constructor called.\n";
	this->type = copy.type;
}

WrongCat& WrongCat::operator=(const WrongCat& copy)
{
	std::cout << "WrongCat copy operator called.\n";
	this->type = copy.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called.\n";
}

void WrongCat::makeSound() const
{
	std::cout << "Meow~\n";
}
