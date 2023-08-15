#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Cat default constructor called\n";
}

Cat::Cat(const Cat &copy) : Animal()
{
	this->type = copy.type;
	std::cout << "Cat copy constructor called\n";
}

Cat &Cat::operator=(const Cat &copy)
{
	this->type = copy.type;
	std::cout << "Cat copy operator called\n";
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called.\n";
}

void Cat::makeSound() const
{
	std::cout << "Meow~\n";
}
