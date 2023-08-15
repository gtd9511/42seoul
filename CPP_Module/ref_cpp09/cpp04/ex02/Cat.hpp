#pragma once
#ifndef Cat_HPP
#define Cat_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *brain;

public:
	Cat();
	Cat(const Cat &copy);
	Cat &operator=(const Cat &copy);
	~Cat();

	void setIdea(std::string idea);
	void showIdeas() const;
	std::string getIdea(int num) const;
	void makeSound() const;
};

#endif // Cat_HPP