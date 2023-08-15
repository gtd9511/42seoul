#pragma once
#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
        static const int SIGN = 145;
        static const int EXEC = 137;
public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& copy);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
        ~ShrubberyCreationForm();

        virtual void execute(Bureaucrat const & executor) const;


};

#endif // ShrubberyCreationForm_HPP