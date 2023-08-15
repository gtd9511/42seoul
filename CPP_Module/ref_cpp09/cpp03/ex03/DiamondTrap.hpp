#pragma once
#ifndef DiamondTrap_HPP
# define DiamondTrap_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
        std::string name;
public:
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& DiamondTrap);
        DiamondTrap& operator=(const DiamondTrap& DiamondTrap);
        ~DiamondTrap();
        void attack();

        void whoAmI();
      
};

#endif // DiamondTrap_HPP