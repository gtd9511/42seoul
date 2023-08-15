#include "ScavTrap.hpp"

int main()
{
	{

		ScavTrap trap1("First");
		ScavTrap trap2("Second");

		trap1.attack("Second");
		trap1.showInfo();
		trap1.takeDamage(10);
		trap1.showInfo();
		trap1.guardGate();


		std::cout << "\n\n\nCopy operator test " << std::endl;
		trap2 = trap1;
		trap2.showInfo();

		std::cout << "\n\n\nCopy constructor test " << std::endl;
		ScavTrap trap3(trap2);
		trap3.showInfo();
		std::cout << std::endl << std::endl << std::endl;
	}
	{
		std::cout << std::endl << std::endl << std::endl;
		ScavTrap *trap3 = new ScavTrap("Third");
		trap3->attack("First");
		trap3->takeDamage(10);
		trap3->showInfo();
		trap3->beRepaired(10);
		trap3->showInfo();
		trap3->guardGate();
		delete trap3;
	}
	{
		std::cout << std::endl << std::endl << std::endl;
		ClapTrap *trap3 = new ScavTrap("Third");
		trap3->attack("First");
		trap3->takeDamage(10);
		trap3->showInfo();
		trap3->beRepaired(10);
		trap3->showInfo();
		// trap3->guardGate();
		delete trap3;
	}



		
	
}