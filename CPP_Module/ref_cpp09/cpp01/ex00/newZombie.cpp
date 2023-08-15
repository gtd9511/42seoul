#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie *zombie = new Zombie;
	zombie->setname(name);
	std::cout << "new zomibe create : " << name << "\n";
	return zombie;
}
