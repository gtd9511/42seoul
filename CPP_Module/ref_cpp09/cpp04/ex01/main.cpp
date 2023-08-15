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
		// subject
		const Animal *j = new Dog();
		const Animal *i = new Cat();

		delete j; // should not create a leak
		delete i;
	}
	{
		std::cout << std::endl
				  << std::endl;
		// Cat, Dog 절반, new로 생성하는 것과 소멸자에서 Brain delete하는 것 확인
		std::cout << "\n\ntest 2\n";
		const int NUM_ANIMALS = 6;
		Animal *animals[NUM_ANIMALS];
		for (int i = 0; i < NUM_ANIMALS / 2; i++)
		{
			animals[i] = new Dog();
		}

		for (int i = NUM_ANIMALS / 2; i < NUM_ANIMALS; i++)
		{
			animals[i] = new Cat();
		}
		std::cout << "\n\n----------destruct---------\n";
		for (int i = 0; i < NUM_ANIMALS; i++)
		{
			std::cout << "destruct " << i << "\n";
			delete animals[i];
		}
	}
	{
		// 복사 연산자 - 깊은 복사 확인
		std::cout << std::endl
				  << std::endl;
		std::cout << "\n\ntest 3\n\n";
		Cat cat1;
		Cat cat2;
		cat1.setIdea("wow!");
		cat1.showIdeas();

		cat2.setIdea("hihi");
		cat2.showIdeas();
		cat2 = cat1;
		cat2.showIdeas();//cat1처럼 "wow"출력해야. 
	}
	{
		// 복사 생성자
		std::cout << std::endl
				  << std::endl;
		std::cout << "\n\ntest4\n\n";
		Cat cat1;
		cat1.setIdea("wow!");
		cat1.setIdea("wow2!");
		cat1.setIdea("wow3!");
		Cat cat2(cat1);
		cat1.showIdeas();
		cat2.showIdeas();
	}
	// atexit(check);
}
