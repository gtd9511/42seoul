#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
:ClapTrap(name, INIT_HP, INIT_EP, INIT_AD )
{
    std::cout << "ScavTrap constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& copy)
:ClapTrap(copy.name, copy.hit_points, copy.energy_points, copy.attack_damage)
{
    std::cout << "ScavTrap copy 'constructor' called\n";  
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
    this->hit_points = copy.hit_points;
    this->energy_points = copy.energy_points;
    this->attack_damage = copy.attack_damage;
    std::cout << "ScavTrap copy 'operator' called\n";
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap default destructor called." << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now on Gate keeper mode.\n";
}

void ScavTrap::attack(const std::string &target)
{
    if (this->energy_points > 0  && this->hit_points > 0)
    {
        std::cout << "ScavTrap "  << this->name << " attacks " << target << " causing " << this->attack_damage << " points of damage." << std::endl;
        this->energy_points--;
    }
    else
    {
        std::cout << "ScavTrap " << this->name << " couldn't attack : no energy!\n";   
    }

}

void ScavTrap::showInfo() const
{
    std::cout << "ScavTrap name " << this->name << " hit points : [" << this->hit_points <<"] energy_points: [" << this->energy_points << "] attack_damage : [" << this->attack_damage << "] "<<std::endl;
}