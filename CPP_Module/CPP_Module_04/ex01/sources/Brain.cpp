/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:02:21 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/23 20:54:21 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain(void)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = 'A' + (i % 26);
	std::cout << "[Brain Class] Constructor called" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "[Brain Class] Destructor called" << std::endl;
}

Brain::Brain(const Brain& obj)
{
	if (this == &obj)
		return ;
	std::cout << "[Brain Class] Copy Constructor called" << std::endl;
	*this = obj;
}

Brain& Brain::operator=(const Brain& obj)
{
	if (this != &obj)
	{
		for (int i = 0; i < 100; i++)
		{
			this->_ideas[i] = obj.getIdeas(i);
		}
	}
	return (*this);
}

std::string	Brain::getIdeas(int n) const
{
	return (this->_ideas[n]);
}

void	Brain::setIdeas(std::string idea, int n)
{
	if (n >= 0 && n < 100)
		this->_ideas[n] = idea;
	else
	 	std::cout << "Error, Out of index. Brain Array Size is 100" << std::endl;
}

