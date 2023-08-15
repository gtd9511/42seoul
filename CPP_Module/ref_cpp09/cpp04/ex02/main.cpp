#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

void check()
{
	system("leaks AnimalBrain");
}

int main()
{
	{
		// Animal *wrong = new Animal();
		Animal *Aptr = new Cat();
		Animal *Aptr2 = new Dog();

		Aptr->makeSound();
		Aptr2->makeSound();
		std::cout << std::endl;
		delete Aptr;
		delete Aptr2;
	}
	{
		std::cout << std::endl;
		std::cout << "\n\ntest2\n\n";
		Dog *Dptr = new Dog();
		Cat *Cptr = new Cat();
		Dptr->makeSound();
		Cptr->makeSound();

		std::cout << std::endl;

		delete Dptr;
		delete Cptr;
	}
	{
	}

	// atexit(check);
}
