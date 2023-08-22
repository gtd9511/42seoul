/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:05:37 by sanghan           #+#    #+#             */
/*   Updated: 2023/08/22 16:51:13 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

std::string Contact::getFirstname(void)
{
	return this->f_name;
}

std::string Contact::getLastname(void)
{
	return this->l_name;
}

std::string Contact::getNickname(void)
{
	return this->n_name;
}

std::string Contact::getPhonenumber(void)
{
	return this->p_num;
}

std::string Contact::getDarkestsecret(void)
{
	return this->darkest_secret;
}

void	Contact::setFirstname(std::string input)
{
	this->f_name = input;
}

void	Contact::setLastname(std::string input)
{
	this->l_name = input;
}

void	Contact::setNickname(std::string input)
{
	this->n_name = input;
}

void	Contact::setPhonenumber(std::string input)
{
	this->p_num = input;
}

void	Contact::setDarkestsecret(std::string input)
{
	this->darkest_secret = input;
}

