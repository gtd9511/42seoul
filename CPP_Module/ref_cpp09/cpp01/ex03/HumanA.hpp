#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP
#include "Weapon.hpp"

class	HumanA
{
private:
		Weapon &weapon;
		std::string  name;
public:
		HumanA(Weapon &weapon);
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		
		void attack();
		
};

#endif