#include "Zombie.hpp"

Zombie::Zombie()
{

}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout << this->name << " : " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{	
	std::cout << "delete " << this->name <<std::endl;
}

void Zombie::setname(std::string name)
{
	this->name = name;
}
