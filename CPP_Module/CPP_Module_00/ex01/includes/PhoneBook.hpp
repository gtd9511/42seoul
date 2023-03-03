/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:05:35 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/02 19:26:05 by sanghan          ###   ########.fr       */
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
		std::string	getContactInfo(void);
		void		search(void);
		std::string	checkColumn(std::string column);
};

#endif
