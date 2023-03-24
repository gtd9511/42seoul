/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:47:00 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/24 21:40:26 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <functional>
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
	private:
		const std::string	_name;
		int	_grade;
		const static int	_maxgrade = 150;
		const static int	_mingrade = 1;

	public:
		Bureaucrat(void);
		~Bureaucrat(void);
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat& operator=(const Bureaucrat& obj);

		Bureaucrat(const std::string name, int grade);

		const std::string & getName() const;
		int	getGrade() const;
		void	increment(void);
		void	decrement(void);
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

std::ostream& operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
