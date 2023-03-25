/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:37:52 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/25 16:12:57 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool	_signed;
		const int _signGrade;
		const int _executeGrade;

	public:
		Form(void);
		~Form(void);
		Form(const Form& obj);
		Form& operator=(const Form& obj);

		Form(const std::string name, const int& signGrade, const int& executeGrade);

		const std::string & getName(void) const;
		const bool&	getSigned(void) const;
		const int& getSignGrade(void) const;
		const int& getExecuteGrade(void) const;

		void	beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException: public std::exception
		{
			public:
				const char* what(void) const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				const char* what(void) const throw();
		};
};

std::ostream& operator<<(std::ostream &out, const Form &form);

#endif
