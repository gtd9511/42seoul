#pragma once
#ifndef ClapTrap_HPP
# define ClapTrap_HPP

#include <iostream>

class ClapTrap
{
protected:
		std::string name;
		unsigned int hit_points;
		unsigned int energy_points;
		unsigned int attack_damage;
public:
		ClapTrap(std::string name);
		ClapTrap(std::string name , unsigned int hit_points, unsigned int energy_points, unsigned int attack_damage );
		ClapTrap(const ClapTrap& claptrap);
		ClapTrap& operator=(const ClapTrap& copy);
		virtual ~ClapTrap();

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
		std::string get_name() const;
		void showInfo() const ;
};

#endif // ClapTrap_HPP