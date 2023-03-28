/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:51:55 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/28 15:23:33 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern
{
	private:
		AForm *f[3];

	public:
		Intern(void);
		virtual ~Intern(void);
		Intern(const Intern& obj);
		Intern& operator=(const Intern& obj);

		AForm*	makeForm(std::string name, std::string target);

		class WrongForm : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};

};

#endif
