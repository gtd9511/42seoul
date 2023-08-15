#pragma once
#ifndef Animal_HPP
# define Animal_HPP

#include <iostream>
#include <stdlib.h>

class Animal
{
protected:
		std::string type;
public:
		Animal();
		Animal(const Animal &copy);
		Animal& operator=(const Animal &copy);
		virtual ~Animal();

		virtual void makeSound() const;

		std::string getType() const;
		void setType(std::string type);	
};

#endif // Animal_HPP