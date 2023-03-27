/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:51:55 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/27 19:23:42 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern
{
	public:
		Intern(void);
		virtual ~Intern(void);
		Intern(const Intern& obj);
		Intern& operator=(const Intern& obj);

		AForm*	makeForm(std::string name, std::string target);
};

#endif
