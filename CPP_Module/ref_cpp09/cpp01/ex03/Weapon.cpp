#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon()
{
	std::cout << "delete weapon " << this->type << std::endl;
}

void Weapon::setType(std::string type)
{
	this->type = type;
}

const std::string &Weapon::getType()const
{
	return (this->type);
}
