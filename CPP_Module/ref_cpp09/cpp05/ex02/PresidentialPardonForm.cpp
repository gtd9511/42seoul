#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, SIGN, EXEC)
{
    std::cout << "PresidentialPardonForm has been created.\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy.getName(), SIGN, EXEC)
{
    std::cout << "PresidentialPardonForm " << copy.getName() << " copy constructor has been called.\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
    std::cout << "(cannot change form's name)\n" ;
    this->setRequiredGradeSign(copy.getRequiredGradeSign());
    this->setRequiredGradeExecute(copy.getRequiredGradeExecute());
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor has been called.\n";
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    AForm::check(executor);
    std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox.\n";
}
