#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
:ClapTrap(name), hit_points(INIT_HP), energy_points(INIT_EP), attack_damage(INIT_AD)
{
    std::cout << "FragTrap constructor called.\n";
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy.name)
{
    std::cout << "FragTrap copy constructor called.\n";
    *this = copy;
}

FragTrap& FragTrap::operator=(const FragTrap& copy)
{
    std::cout << "FragTrap copy operator called.\n";
    this->hit_points = copy.hit_points;
	this->energy_points = copy.energy_points;
	this->attack_damage = copy.attack_damage;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FlagTrap destructor called.\n";
}

void FragTrap::highFiveGuys()
{
    std::cout << "[ " << get_name() << " ] : " << "let's highfive guys!\n";
}

