#pragma once
#ifndef Intern_HPP
# define Intern_HPP
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{

private: 
        class noSuchForm: public std::exception{
                virtual const char *what(void) const throw();
        }; 
public:
        Intern();
        Intern(const Intern& copy);
        Intern& operator=(const Intern& copy);
        ~Intern();

        AForm *makeForm(std::string name, std::string target);
};

#endif // Intern_HPP