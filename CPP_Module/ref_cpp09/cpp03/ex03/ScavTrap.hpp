#pragma once
#ifndef ScavTrap_HPP
# define ScavTrap_HPP

#include "ClapTrap.hpp"
class ScavTrap : virtual public ClapTrap
{

private:
protected: 
	enum{
		INIT_HP = 100,
		INIT_EP = 50,
		INIT_AD = 20
	};
public:
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& copy);
        ScavTrap& operator=(const ScavTrap& copy);
        ~ScavTrap();

        void guardGate();

};

#endif // ScavTrap_HPP