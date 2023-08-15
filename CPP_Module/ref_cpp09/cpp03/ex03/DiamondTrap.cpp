#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
:ClapTrap(name + "_clap_name", FragTrap::INIT_HP, ScavTrap::INIT_EP, FragTrap::INIT_AD),ScavTrap(name), FragTrap(name), name(name)
{
    std::cout << "DiamondTrap constructor called : " <<  name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "called DiamondTrap destructor.\n" ;
}
void DiamondTrap::whoAmI()
{
    std::cout <<"I am both ScavTrap and FragTrap, I am " << name << " and both " << ClapTrap::get_name() <<".\n";
}

void DiamondTrap::attack()
{
    ScavTrap::attack();
}

