#include "Zombie.hpp"

void check()
{
	system("leaks Zombie");
}

int main()
{
	Zombie *zombiehorde = zombieHorde(10, "ebang");
	for(int i =0; i < 10; i++)
	{
		zombiehorde[i].announce();
		std::cout << "\n";
	}
	delete []zombiehorde;
	atexit(check); 
}