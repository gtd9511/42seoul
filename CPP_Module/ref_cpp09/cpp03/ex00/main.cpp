#include "ClapTrap.hpp"

int main()
{
	{
		ClapTrap ct1("ebang");
		ClapTrap ct2("seongmik");

		ct1.beRepaired(10);
		ct1.attack(ct2.get_name());
		ct2.takeDamage(ct1.get_attack_damage());
		
	}
	{
		std::cout << std::endl << std::endl << std::endl;
		ClapTrap ct1("ebang");
		ClapTrap ct2("seongmik");

		ct1.beRepaired(5);
		ct1.attack(ct2.get_name());
		ct2.takeDamage(ct1.get_attack_damage());

		ct1.attack(ct2.get_name());
		ct2.takeDamage(ct1.get_attack_damage());

	}
}