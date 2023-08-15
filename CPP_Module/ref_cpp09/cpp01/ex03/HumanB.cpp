#include "./HumanB.hpp"

HumanB::HumanB(std::string name)
:name(name), weapon(NULL)
{}

HumanB::~HumanB()
{}

void HumanB::attack()
{
	if(this->weapon == NULL)
	{
		std::cout << this->name << " cannot attack: no weapon.\n" << std::endl;
		return ;
	}
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}