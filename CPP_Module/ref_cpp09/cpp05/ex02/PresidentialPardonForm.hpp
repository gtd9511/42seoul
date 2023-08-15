#pragma once
#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

#include "AForm.hpp"
class PresidentialPardonForm : public AForm
{
private:
        static const int SIGN = 25;
        static const int EXEC = 5;
public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& copy);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
        ~PresidentialPardonForm();
        virtual void execute(Bureaucrat const & executor) const;
        
};

#endif // PresidentialPardonForm_HPP