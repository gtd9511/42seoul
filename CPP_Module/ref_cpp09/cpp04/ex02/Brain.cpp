#include "Brain.hpp"

Brain::Brain()
:num(0)
{
	std::cout << "Brain default constructor called.\n";
}

Brain::Brain(const Brain&  copy)
{
	std::cout << "Brain copy constructor called.\n";
	for(int i = 0; i < num; i++)
		this->ideas[i] = copy.ideas[i].substr();
}

Brain& Brain::operator=(const Brain& copy)
{
	std::cout << "Brain copy operator called.\n";
	for(int i = 0; i < num; i++)
		this->ideas[i] = copy.ideas[i].substr();
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain default destructor called.\n";
}

void Brain::setIdea(std::string idea)
{
	if(num < 100)
	{
		this->ideas[num] = idea.substr(0);
		num++; 
	}
}

void Brain::showIdeas()
{
	for(int i = 0; i < num; i++)
		std::cout << ideas[i] << "\n";
	return ;
}


int Brain::getNum()
{
	return num;
}

std::string Brain::getIdea(int num) const
{
	if(num <= this->num)
		return ideas[num];
	else
		return NULL;
}

void Brain::numIncrease()
{
	this->num++;
}