#include "Dog.hpp"

Dog::Dog()
	: Animal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog default constructor called\n";
}

Dog::Dog(const Dog &copy)
	: Animal()
{
	this->type = copy.type;
	this->brain = new Brain;
	for (int i = 0; i < copy.brain->getNum(); i++)
		this->brain[i] = copy.brain[i];

	std::cout << "Dog copy constructor called\n";
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << "Dog copy operator called\n";
	if (this != &copy)
	{
		if (this->brain != NULL)
			delete this->brain;
		this->type = copy.type;
		this->brain = new Brain();
		for (int i = 0; i < copy.brain->getNum(); i++)
			this->brain->setIdea(copy.brain->getIdea(i));
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called.\n";
	delete this->brain;
}

void Dog::makeSound() const
{
	std::cout << "Bow Wow!\n";
}

void Dog::setIdea(std::string idea)
{
	if (this->brain->getNum() < 100)
	{
		this->brain->setIdea("Dog's idea : " + idea.substr(0));
		this->brain->numIncrease();
	}
}

std::string Dog::getIdea(int num) const
{
	return this->brain->getIdea(num);
}

void Dog::showIdeas() const
{
	this->brain->showIdeas();
	return;
}