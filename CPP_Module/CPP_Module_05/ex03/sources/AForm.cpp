/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:49:15 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/27 17:12:21 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm(void): _name("default"), _signed(false), _signGrade(150), _executeGrade(150)
{
	std::cout << "AForm Class : " << this->_name << " Constructor called" << std:: endl;
}

AForm::~AForm(void)
{
	std::cout << "AForm Class : " << this->_name << " Destructor called" << std:: endl;
}

AForm::AForm(const AForm& obj): _name(obj._name), _signed(obj._signed), _signGrade(obj._signGrade), _executeGrade(obj._executeGrade)
{
	if (this == &obj)
		return ;
	std::cout << "AForm Class : " << this->_name << "] Copy Constructor called" << std:: endl;
	*this = obj;
}

AForm& AForm::operator=(const AForm& obj)
{
	if (this != &obj)
	{
		const_cast<std::string&>(this->_name) = obj._name;
		const_cast<bool&>(this->_signed) = obj._signed;
		const_cast<int&>(this->_signGrade) = obj._signGrade;
		const_cast<int&>(this->_executeGrade) = obj._executeGrade;
	}
	return (*this);
}

AForm::AForm(const std::string name, const int& signGrade, const int& executeGrade): _name(name), _signed(0), _signGrade(signGrade), _executeGrade(executeGrade)
{
	std::cout << "AForm Class : " << this->_name << " Constructor called" << std:: endl;
}

const std::string & AForm::getName(void) const
{
	return (this->_name);
}

const bool&	AForm::getSigned(void) const
{
	return (this->_signed);
}

const int& AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}

const int& AForm::getExecuteGrade(void) const
{
	return (this->_executeGrade);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (!this->_signed)
	{
		if (this->_signGrade >= bureaucrat.getGrade())
		{
			_signed = true;
			std::cout << "Permission Signed" << std::endl;
		}
		else
		 	throw GradeTooLowException();
	}
	else
		std::cout << "Alreay Signed" << std::endl;
}

const char* AForm::GradeTooHighException::what(void) const throw()
{
	return ("It is rated outside the highest grade");
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
	return ("Too Low Grade");
}

const char* AForm::SignedException::what(void) const throw()
{
	return ("Forbidden Permission Signed.");
}

void	AForm::setName(std::string name)
{
	const_cast<std::string&>(this->_name) = name;
}

void	AForm::setSigned(bool b)
{
	this->_signed = b;
}

std::ostream& operator<<(std::ostream &out, const AForm &aform)
{
	out <<  "[" << aform.getName()
		<< "] [signed : " << (aform.getSigned() ? "signed" : "not signed")
		<< "] [sign grade : " << aform.getSignGrade()
		<< "] [execute grade : " << aform.getExecuteGrade()
		<< "]" <<std::endl;
	return out;
}
