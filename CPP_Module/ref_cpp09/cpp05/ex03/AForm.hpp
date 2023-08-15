#pragma once
#ifndef AForm_HPP
# define AForm_HPP
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
private:
        const std::string name;
        int requiredGradeSign;
        int requiredGradeExecute;
        bool ifSigned;
         //exception handling
       
public:
        AForm(std::string name, int requiredGradeSign, int requiredGradeExecute);
        AForm(const AForm& copy);
        AForm& operator=(const AForm& copy);
        virtual ~AForm();

        //getters
        int getRequiredGradeSign() const;
        int getRequiredGradeExecute() const;
        std::string getName() const;
        bool getIfSigned() const;
        
        void setRequiredGradeSign(int grade);
        void setRequiredGradeExecute(int grade);

        void beSigned(const Bureaucrat &b);
        void check(Bureaucrat const & executor) const;

        //virtual
        virtual void execute(Bureaucrat const & executor) const = 0; 
         class formNotSigned: public std::exception{     
                virtual const char *what(void) const throw();
        };
        
        class GradeTooHighException: public std::exception{
                virtual const char *what(void) const throw();
        };

        class GradeTooLowException: public std::exception{
                virtual const char *what(void) const throw();
        };
        class HasAlreadyBeenSigned: public std::exception{
                virtual const char *what(void) const throw();
        };


};

std::ostream &operator<<(std::ostream &os, const AForm &f);
#endif // Form_HPP