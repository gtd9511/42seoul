/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:41:38 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/27 17:45:48 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"
#include <cstddef>

RobotomyRequestForm::RobotomyRequestForm(void): AForm("robotomyrequest", 72, 45), _target("no target")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("robotomyrequest", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj), _target(obj._target)
{
	if (this == &obj)
		return ;
	*this = obj;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	if (this != &obj)
	{
		this->setSigned(obj.getSigned());
		this->_target = obj._target;
	}
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	std::time_t	currentTime = std::time(nullptr);
	
	if (!this->getSigned())
		throw (AForm::SignedException());
	else if (executor.getGrade() > this->getExecuteGrade())
		throw (AForm::GradeTooLowException());
	else
	{
		std:: cout << "Drrrrrrrrrrr....." << std::endl;
		(currentTime % 2 == 0) ?
		std::cout << this->_target << " has been robotomized successful" << std::endl :
		std::cout << this->_target << " has been robotomized failed" << std::endl;
	}
}
