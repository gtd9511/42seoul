/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:42:37 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/27 15:27:31 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include <exception>

Bureaucrat::Bureaucrat(void): _name("default"), _grade(150)
{
	std::cout << "Bureaucrat Class : " << this->_name << " Grade [" << this->_grade << "] Constructor called" << std:: endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat Class : " << this->_name << " Grade [" << this->_grade << "] Destructor called" << std:: endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj): _name(obj._name), _grade(obj._grade)
{
	if (this == &obj)
		return ;
	std::cout << "Bureaucrat Class : " << this->_name << " Grade [" << this->_grade << "] Copy Constructor called" << std:: endl;
	*this = obj;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	if (this != &obj)
	{
		const_cast<std::string&>(this->_name) = obj._name;
		this->_grade = obj._grade;
	}
	return (*this);
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
	if (grade > _maxgrade)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < _mingrade)
		throw Bureaucrat::GradeTooHighException();
	else
	 {
		this->_grade = grade;
		std::cout << "Bureaucrat Class : " << this->_name << " Grade [" << this->_grade << "] Constructor called" << std:: endl;
	 }
}

const std::string & Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::increment(void)
{
	if (this->_grade < 2)
		throw Bureaucrat::GradeTooHighException();
	else
	 	this->_grade--;
}

void	Bureaucrat::decrement(void)
{
	if (this->_grade > 149)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("It is rated outside the highest grade");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("It is rated outside the lowest grade");
}

void	Bureaucrat::signForm(AForm& aform)
{
	try
	{
		aform.beSigned(*this);
		std::cout << this->_name << " sigend " << aform.getName() <<std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << this->_name << " couldn't sign " << aform.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & aform)
{
	try
	{
		aform.execute(*this);
		std::cout << this->getName() << " executed " << aform.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " couldn't execute " << aform.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (out);
}
