#include "AForm.hpp"


AForm::AForm(std::string name, int requiredGradeSign, int requiredGradeExecute) : name(name), requiredGradeSign(requiredGradeSign), requiredGradeExecute(requiredGradeExecute), ifSigned(false)
{
    if(requiredGradeExecute < 1 || requiredGradeSign < 1)
        throw GradeTooHighException();
    if(requiredGradeExecute > 150 || requiredGradeSign > 150)
        throw GradeTooLowException();
    std::cout << "Form " << name << " requiredGradeForSign [" << requiredGradeSign << "] " << " requiredGradeForExecute ["  << requiredGradeExecute << "] created.\n";
}

AForm::AForm(const AForm& copy) : name(copy.name) , requiredGradeSign(copy.requiredGradeSign) , requiredGradeExecute(copy.requiredGradeExecute) , ifSigned(false)
{
    std::cout << "Form copy constructor called.\n";
}

AForm& AForm::operator=(const AForm& copy)
{
    std::cout << "Form copy operator called.\n";
    std::cout << "cannot change Form's name\n";
    this->ifSigned = copy.ifSigned;
    this->requiredGradeSign = copy.requiredGradeSign;
    this->requiredGradeExecute = copy.requiredGradeExecute;
    return *this;
}

AForm::~AForm()
{
    std::cout << "Form destructor called.\n";
}

int AForm::getRequiredGradeSign() const
{
    return this->requiredGradeSign;
}

int AForm::getRequiredGradeExecute() const
{
    return this->requiredGradeExecute;
}

std::string AForm::getName() const
{
    return this->name;
}

bool AForm::getIfSigned() const
{
    return this->ifSigned;
}

void AForm::setRequiredGradeSign(int grade)
{
    if(grade < 1 )
        throw GradeTooHighException();
    else if(grade > 150)
        throw GradeTooLowException();
    this->requiredGradeSign = grade;
}

void AForm::setRequiredGradeExecute(int grade)
{
    if(grade < 1 )
        throw GradeTooHighException();
    else if(grade > 150)
        throw GradeTooLowException();
    this->requiredGradeExecute = grade;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (this->requiredGradeSign < b.getGrade())
        throw GradeTooHighException();
    else if(this->ifSigned == true)
        throw HasAlreadyBeenSigned();
    else
        this->ifSigned = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
    os << f.getName() << " signGrade [" << f.getRequiredGradeSign() << "] executeGrade ["  << f.getRequiredGradeExecute() << "]\n";
    return os;
}

void AForm::check(Bureaucrat const & executor) const
{
    if (this->ifSigned == false)
        throw formNotSigned();
    else if(this->requiredGradeExecute < executor.getGrade())
        throw GradeTooHighException();
}

const char *AForm::formNotSigned::what(void) const throw()
{
    return "Form was not signed.\n";
}

const char *AForm::GradeTooHighException::what() const throw ()
{
    return "Grade was too high for the Bureaucrat.\n";
}

const char *AForm::GradeTooLowException::what() const throw ()
{
    return "Grade was too low for the Bureaucrat.\n";
}

const char *AForm::HasAlreadyBeenSigned::what() const throw ()
{
    return "Form was already signed.\n";
}

