/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:05:32 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/03 14:39:17 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
	private:
		std::string	f_name;
		std::string	l_name;
		std::string	n_name;
		std::string	p_num;
		std::string	darkest_secret;

	public:
		std::string getFirstname(void);
		std::string getLastname(void);
		std::string getNickname(void);
		std::string getPhonenumber(void);
		std::string getDarkestsecret(void);
		void		setFirstname(std::string input);
		void		setLastname(std::string input);
		void		setNickname(std::string input);
		void		setPhonenumber(std::string input);
		void		setDarkestsecret(std::string input);
};

#endif
