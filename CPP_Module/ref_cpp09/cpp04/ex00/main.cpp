#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		i->makeSound();
		j->makeSound();
		meta->makeSound();
	}
	{
		std::cout << std::endl
				  << std::endl;
		Dog *dog = new Dog();
		Cat *cat = new Cat();

		dog->makeSound();
		cat->makeSound();
		delete dog;
		delete cat;
	}
	{
		std::cout << std::endl
				  << std::endl;
		WrongAnimal *wa = new WrongCat();

		WrongCat *wc = new WrongCat();
		wa->makeSound();
		wc->makeSound();

		std::cout << std::endl
				  << std::endl;

		delete wa;
		delete wc;
	}
}
