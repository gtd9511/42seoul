#pragma once
#ifndef ScavTrap_HPP
# define ScavTrap_HPP

#include "ClapTrap.hpp"
class ScavTrap : public ClapTrap
{
private:
enum{
	INIT_HP = 100,
        INIT_EP = 50,
	INIT_AD = 20
};
public:
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& copy);
        ScavTrap& operator=(const ScavTrap& copy);
        virtual ~ScavTrap();

        void guardGate();
        void attack(const std::string &target); 
        void showInfo() const;
};

#endif // ScavTrap_HPP