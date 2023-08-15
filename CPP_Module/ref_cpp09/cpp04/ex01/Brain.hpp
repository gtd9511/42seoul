#pragma once
#ifndef Brain_HPP
#define Brain_HPP

#include <iostream>

class Brain
{
private:
	std::string ideas[100];
	int num;

public:
	Brain();
	Brain(const Brain &copy);
	Brain &operator=(const Brain &copy);
	~Brain();

	void setIdea(std::string idea);
	void showIdeas();
	std::string getIdea(int num) const;
	int getNum();
	void numIncrease();
};

#endif // Brain_HPP