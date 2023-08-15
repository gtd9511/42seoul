#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) :ClapTrap(name, INIT_HP, INIT_EP, INIT_AD)
{
    std::cout << "FragTrap constructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy)
:ClapTrap(copy.name, copy.hit_points, copy.energy_points, copy.attack_damage)
{
    std::cout << "FragTrap copy constructor called." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy)
{
    std::cout << "FragTrap copy operator called." << std::endl;
    this->hit_points = copy.hit_points;
    this->energy_points = copy.energy_points;
    this->attack_damage = copy.attack_damage;
    return *this;
}

FragTrap::~FragTrap()
{
     std::cout << "FragTrap destructor called." << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if (this->energy_points > 0  && this->hit_points > 0)
    {
        std::cout << "FragTrap "  << this->name << " attacks " << target << " causing " << this->attack_damage << " points of damage." << std::endl;
        this->energy_points--;
    }
    else
    {
        std::cout << "FragTrap " << this->name << " couldn't attack : no energy!\n";   
    }
}

void FragTrap::showInfo() const
{
    std::cout << "FragTrap name " << this->name << " hit points : [" << this->hit_points <<"] energy_points: [" << this->energy_points << "] attack_damage : [" << this->attack_damage << "] "<<std::endl;
}

