#include "Form.hpp"


Form::Form(std::string name, int requiredGradeSign, int requiredGradeExecute) : name(name), requiredGradeSign(requiredGradeSign), requiredGradeExecute(requiredGradeExecute), ifSigned(false)
{
    if(requiredGradeExecute < 1 || requiredGradeSign < 1)
        throw GradeTooHighException();
    if(requiredGradeExecute > 150 || requiredGradeSign > 150)
        throw GradeTooLowException();
    std::cout << "Form " << name << " requiredGradeForSign [" << requiredGradeSign << "] " << " requiredGradeForExecute ["  << requiredGradeExecute << "] created.\n";
}

Form::Form(const Form& copy) : name(copy.name) , requiredGradeSign(copy.requiredGradeSign) , requiredGradeExecute(copy.requiredGradeExecute) , ifSigned(false)
{
    std::cout << "Form copy constructor called.\n";
}

Form& Form::operator=(const Form& copy)
{
    std::cout << "Form copy operator called.\n";
    std::cout << "cannot change Form's name\n";
    this->ifSigned = copy.ifSigned;
    this->requiredGradeSign = copy.requiredGradeSign;
    this->requiredGradeExecute = copy.requiredGradeExecute;
    return *this;
}

Form::~Form()
{
    std::cout << "Form destructor called.\n";
}

int Form::getRequiredGradeSign() const
{
    return this->requiredGradeSign;
}

int Form::getRequiredGradeExecute() const
{
    return this->requiredGradeExecute;
}

std::string Form::getName() const
{
    return this->name;
}

bool Form::getIfSigned() const
{
    return this->ifSigned;
}

void Form::beSigned(const Bureaucrat &b)
{
    if (this->requiredGradeSign < b.getGrade())
        throw GradeTooHighException();
    else if(this->ifSigned == true)
        throw HasAlreadyBeenSigned();
    else
        this->ifSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
    os << f.getName() << " signGrade [" << f.getRequiredGradeSign() << "] executeGrade ["  << f.getRequiredGradeExecute() << "]\n";
    return os;
}

const char *Form::GradeTooHighException::what() const throw ()
{
    return "Grade was too high for the Bureaucrat.\n";
}

const char *Form::GradeTooLowException::what() const throw ()
{
    return "Grade was too low for the Bureaucrat.\n";
}

const char *Form::HasAlreadyBeenSigned::what() const throw ()
{
    return "Form was already signed.\n";
}