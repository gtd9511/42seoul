#pragma once
#ifndef ClapTrap_HPP
# define ClapTrap_HPP

#include <iostream>

class ClapTrap
{
private:
		std::string name;
		int hit_points;
		int energy_points;
		int attack_damage;
		
protected:
	enum{
		INIT_HP = 10,
		INIT_EP = 10,
		INIT_AD = 0
	};

public:
		ClapTrap(std::string name);
		ClapTrap(std::string name, int hp, int ep, int ad);
		ClapTrap(const ClapTrap& claptrap);
		ClapTrap& operator=(const ClapTrap& copy);
		~ClapTrap();

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		int get_hit_points();
		int get_energy_points();
		int get_attack_damage();
		void showInfo();

	 	std::string get_name();
};

#endif // ClapTrap_HPP