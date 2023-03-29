/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:37:52 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/27 14:29:58 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool	_signed;
		const int _signGrade;
		const int _executeGrade;

	public:
		AForm(void);
		virtual ~AForm(void);
		AForm(const AForm& obj);
		AForm& operator=(const AForm& obj);

		AForm(const std::string name, const int& signGrade, const int& executeGrade);

		const std::string & getName(void) const;
		const bool&	getSigned(void) const;
		const int& getSignGrade(void) const;
		const int& getExecuteGrade(void) const;

		void	beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};

		class SignedException : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};

		virtual void	execute(Bureaucrat const & executor) const = 0;
		void	setName(std::string name);
		void	setSigned(bool b);
};

std::ostream& operator<<(std::ostream &out, const AForm &Aform);

#endif
