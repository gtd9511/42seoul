#include "Animal.hpp"

Animal::Animal()
{ std::cout << "Animal default constructor called\n";}

Animal::Animal(const Animal& copy)
{
	this->type = copy.type;
	std::cout << "Animal copy constructor called\n";
}

Animal& Animal::operator=(const Animal& copy)
{
	this->type = copy.type;
	std::cout << "Animal copy operator called\n";
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called.\n";
}

void Animal::makeSound() const
{
	std::cout << "I am an Animal.\n";
}

std::string Animal::getType() const
{
	return this->type;
}

void Animal::setType(std::string type)
{
	this->type = type;
}