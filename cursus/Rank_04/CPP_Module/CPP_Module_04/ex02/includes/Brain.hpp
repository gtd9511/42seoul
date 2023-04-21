/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:55:47 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/21 14:40:56 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	private:
		std::string	_ideas[100];

	public:
		Brain(void);
		~Brain(void);
		Brain(const Brain& obj);
		Brain& operator=(const Brain& obj);

		std::string	getIdeas(int n) const;
		void	setIdeas(std::string idea, int n);
};

#endif
