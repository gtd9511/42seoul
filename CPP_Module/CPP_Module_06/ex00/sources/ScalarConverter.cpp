/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 08:40:46 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/29 16:42:39 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}
ScalarConverter::~ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
	if (this == &obj)
		return ;
	*this = obj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj)
{
	if (this != &obj)
	{
		(void)obj;
	}
	return (*this);
}

void ScalarConverter::convert(const std::string& input)
{

}

