#pragma once
#ifndef Form_HPP
# define Form_HPP
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
private:
        const std::string name;
        int requiredGradeSign;
        int requiredGradeExecute;
        bool ifSigned;
        class GradeTooHighException: public std::exception{
                virtual const char *what(void) const throw();
        };
        class GradeTooLowException: public std::exception{
                virtual const char *what(void) const throw();
        };
        class HasAlreadyBeenSigned: public std::exception{
                virtual const char *what(void) const throw();
        };

public:
        Form(std::string name, int requiredGradeSign, int requiredGradeExecute);
        Form(const Form& copy);
        Form& operator=(const Form& copy);
        ~Form();

        //getters
        int getRequiredGradeSign() const;
        int getRequiredGradeExecute() const;
        std::string getName() const;
        bool getIfSigned() const;
        void beSigned(const Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &os, const Form &f);
#endif // Form_HPP