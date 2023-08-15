#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Dog default constructor called\n";
}

Dog::Dog(const Dog &copy) : Animal()
{
	this->type = copy.type;
	std::cout << "Dog copy constructor called\n";
}

Dog &Dog::operator=(const Dog &copy)
{
	this->type = copy.type;
	std::cout << "Dog copy operator called\n";
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called.\n";
}

void Dog::makeSound() const
{
	std::cout << "Bow Wow!\n";
}