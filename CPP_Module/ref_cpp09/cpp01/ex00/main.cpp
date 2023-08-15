#include "Zombie.hpp"

void check()
{
	system("leaks Zombie");
}

int main()
{
	Zombie zombie1 = Zombie("stack1");
	zombie1.announce();
	Zombie zombie2 = Zombie("stack2");

	Zombie * zombie3 = newZombie("heap1");
	randomChump("stack3");
	delete zombie3;

	atexit(check);
}