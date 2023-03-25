/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:49:15 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/25 15:35:39 by sanghan          ###   ########.fr       */
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

Form::Form(const std::string name, const int& _signGrade, const int& _executeGrade)
{}

const std::string & Form::getName(void) const
{}

const bool&	Form::getSigned(void) const
{}

const int& Form::getSignGrade(void) const
{}

const int& Form::getExecuteGrade(void) const
{}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{}

const char * Form::GradeTooHighException: public std::exception
{}

const char * Form::GradeTooLowException: public std::exception
{}


