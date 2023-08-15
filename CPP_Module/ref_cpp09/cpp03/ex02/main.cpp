#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	{
		ClapTrap *trap1 = new FragTrap("Frag");
		trap1->attack("First");
		trap1->showInfo();
		trap1->takeDamage(100);
		trap1->showInfo();
		trap1->attack("Second");
		delete trap1;
	}
	{
		std::cout << std::endl << std::endl;
		FragTrap trap1("Frag1");
		ScavTrap trap2("Scav");
		FragTrap trap3("Frag2");
		trap2.attack(trap3.get_name());
		trap3.takeDamage(100);
		trap2.showInfo();
		trap3.showInfo();

		std::cout << "\n\n\nCopy operator test " << std::endl;
		trap1 = trap3;
		trap2.showInfo();
		std::cout << "\n\n\nCopy constructor test " << std::endl;

		FragTrap trap4(trap3);
		trap4.showInfo();
		
	}

}
	