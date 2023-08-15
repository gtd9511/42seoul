#include "ScavTrap.hpp"
ScavTrap::ScavTrap(std::string name)
:ClapTrap(name), hit_points(INIT_HP), energy_points(INIT_EP), attack_damage(INIT_AD)
{
    std::cout << "ScavTrap constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy.name)
{
    *this = copy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
    std::cout << "ScavTrap copy 'operator' called\n";
    this->hit_points = copy.hit_points;
	this->energy_points = copy.energy_points;
	this->attack_damage = copy.attack_damage;

    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap default constructor called.\n";
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << get_name() << " is now on Gate keeper mode.\n";
}