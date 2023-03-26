/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:49:15 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/26 14:34:53 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form(void): _name("default"), _signed(false), _signGrade(150), _executeGrade(150)
{
	std::cout << "Form Class : " << this->_name << " Constructor called" << std:: endl;
}

Form::~Form(void)
{
	std::cout << "Form Class : " << this->_name << " Destructor called" << std:: endl;
}

Form::Form(const Form& obj): _name(obj._name), _signed(obj._signed), _signGrade(obj._signGrade), _executeGrade(obj._executeGrade)
{
	if (this == &obj)
		return ;
	std::cout << "Form Class : " << this->_name << "] Copy Constructor called" << std:: endl;
	*this = obj;
}

Form& Form::operator=(const Form& obj)
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

Form::Form(const std::string name, const int& signGrade, const int& executeGrade): _name(name), _signed(0), _signGrade(signGrade), _executeGrade(executeGrade)
{
	std::cout << "Form Class : " << this->_name << " Constructor called" << std:: endl;
}

const std::string & Form::getName(void) const
{
	return (this->_name);
}

const bool&	Form::getSigned(void) const
{
	return (this->_signed);
}

const int& Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

const int& Form::getExecuteGrade(void) const
{
	return (this->_executeGrade);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->_signGrade >= bureaucrat.getGrade())
		_signed = true;
	else
	 	throw GradeTooLowException();

}

const char* Form::GradeTooHighException::what(void) const throw()
{
	return ("It is rated outside the highest grade");
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return ("Too Low Grade...");
}

std::ostream& operator<<(std::ostream &out, const Form &form)
{
	out <<  form.getName()
		<< ", signed : " << (form.getSigned() ? "signed" : "not signed")
		<< ", sign grade : " << form.getSignGrade()
		<< ", execute grade : " << form.getExecuteGrade()
		<< std::endl;
	return out;
}
