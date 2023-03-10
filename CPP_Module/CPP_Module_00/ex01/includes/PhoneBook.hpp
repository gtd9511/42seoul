/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:05:35 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/10 19:33:26 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>

class PhoneBook
{
	private:
		Contact	contact[8];
		int		index;

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void		add(void);
		std::string	getContact(void);
		void		search(void);
		std::string	checkWidth(std::string column);
		void		Drawline(void);
};

#endif
