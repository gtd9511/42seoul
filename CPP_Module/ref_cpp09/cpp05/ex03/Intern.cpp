#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern has created.\n";
}

Intern::Intern(const Intern& copy)
{
    std::cout << "Intern copy constructor called.\n";
    *this = copy;

}

Intern& Intern::operator=(const Intern& copy)
{
    std::cout << "Intern copy operator called.\n";
    if(this == &copy)
        return *this;

    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern has diasppeared.\n";
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    AForm *form;
    std::string forms[3] = {"presidential pardon", "robotomy request", "shruberry creation"};

    int flag = -1;
    for(int i = 0; i < 3; i++)
    {
        if(formName == forms[i])
        {
            flag = i;
            std::cout << "Intern creates " << forms[i] << ".\n";
            break;
        }
    }
    switch(flag)
    {
        case 0:
            form = new PresidentialPardonForm(target);
            return form;
        case 1 : 
            form = new RobotomyRequestForm(target);
            return form;
        case 2:
            form = new ShrubberyCreationForm(target);
            return form;
        default:
            throw noSuchForm();
    }
}
const char *Intern::noSuchForm::what() const throw ()
{
    return "Cannot create form : there's no such form.\n";
}