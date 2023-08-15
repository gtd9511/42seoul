#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	this->type = copy.type;
	std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
	this->type = copy.type;
	std::cout << "WrongAnimal copy operator called\n";
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called.\n";
}

void WrongAnimal::makeSound() const
{
	std::cout << "I am an WrongAnimal.\n";
}

std::string WrongAnimal::getType() const
{
	return this->type;
}

void WrongAnimal::setType(std::string type)
{
	this->type = type;
}