#include "Bureaucrat.hpp"
const int Bureaucrat::HIGHEST_GRADE = 1;
const int Bureaucrat::LOWEST_GRADE = 150;

Bureaucrat::Bureaucrat(std::string name, int grade) :name(name)
{
    if(grade < HIGHEST_GRADE)
        throw GradeTooHighException();
    else if(grade > LOWEST_GRADE)
        throw GradeTooLowException();
    this->grade = grade;
    std::cout << "Bureaucrat " << name << " grade [" << grade << "] appeared." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) :name(copy.name), grade(copy.grade)
{
    std::cout << "Bureaucrat copy constructor called.\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
    this->grade = copy.grade;
    if(copy.name != this->name)
        std::cout << "(cannot change name)\n";
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << this->name << " disappeared." << std::endl;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

std::string Bureaucrat::getName() const
{
    return this->name;
}

void Bureaucrat::setGrade(int grade)
{
    if(this->grade < HIGHEST_GRADE)
        throw GradeTooHighException();
    if(this->grade > LOWEST_GRADE)
        throw GradeTooLowException();
    this->grade = grade;
}

void Bureaucrat::incrementGrade()
{
    if(this->grade - 1 < HIGHEST_GRADE)
        throw GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrementGrade()
{
    if(this->grade +  1 > LOWEST_GRADE)
        throw GradeTooLowException();
    this->grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw ()
{
    return "Grade was too high\n";
}

const char *Bureaucrat::GradeTooLowException::what() const throw ()
{
    return "Grade was too low\n";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
    os << "Bureaucrat " << obj.getName() << " grade " << obj.getGrade() << "\n";
    return os;
}

void Bureaucrat::signForm(AForm &f)
{
    try
    {
        f.beSigned(*this);
        std:: cout << this->name << " signed the " << f.getName() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << this->name << " couldn't sign the form " << f.getName( ) << " because " <<  e.what();
    }
}

void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
    }
    catch(std::exception &e)
    {
        std::cerr << this->name << " could not execute the form because " << e.what();
    }
}