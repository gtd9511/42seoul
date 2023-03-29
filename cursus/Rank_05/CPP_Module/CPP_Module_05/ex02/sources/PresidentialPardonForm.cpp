/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:41:36 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/27 13:41:03 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("presidential", 25, 5), _target("no target")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("presidential", 25, 5), _target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj): AForm(obj), _target(obj._target)
{
	if (this == &obj)
		return ;
	*this = obj;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
	if (this != &obj)
	{
		this->setSigned(obj.getSigned());
		this->_target = obj._target;
	}
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw (AForm::SignedException());
	else if (executor.getGrade() > this->getExecuteGrade())
		throw (AForm::GradeTooLowException());
	else
	 	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

