#pragma once
#ifndef Dog_HPP
#define Dog_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{

private:
	Brain *brain;

public:
	Dog();
	Dog(const Dog &copy);
	Dog &operator=(const Dog &copy);
	~Dog();

	void setIdea(std::string idea);
	void showIdeas() const;
	std::string getIdea(int num) const;
	void makeSound() const;
};

#endif // Dog_HPP