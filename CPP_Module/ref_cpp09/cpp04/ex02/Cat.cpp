#include "Cat.hpp"

Cat::Cat()
	: Animal()
{
	this->type = "Cat";
	this->brain = new Brain;
	std::cout << "Cat default constructor called\n";
}

Cat::Cat(const Cat &copy)
	: Animal()
{
	this->type = copy.type;
	this->brain = new Brain;
	for (int i = 0; i < copy.brain->getNum(); i++)
		this->brain->setIdea(copy.getIdea(i));
	std::cout << "Cat copy constructor called\n";
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << "Cat copy operator called\n";
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

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat destructor called.\n";
}

void Cat::makeSound() const
{
	std::cout << "Meow~\n";
}

std::string Cat::getIdea(int num) const
{
	return this->brain->getIdea(num);
}

void Cat::setIdea(std::string idea)
{
	if (this->brain->getNum() < 100)
	{
		this->brain->setIdea("Cat's idea : " + idea.substr(0));
		this->brain->numIncrease();
	}
}

void Cat::showIdeas() const
{
	this->brain->showIdeas();
	return;
}