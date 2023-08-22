/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 08:40:46 by sanghan           #+#    #+#             */
/*   Updated: 2023/08/22 16:56:15 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

void	errorMessage(int n)
{
	if (n == 0)
		std::cout << "char: impossible" << std::endl;
	if (n == 1)
		std::cout << "int: impossible" << std::endl;
	if (n == 2)
		std::cout << "float: nanf" << std::endl;
	if (n == 3)
		std::cout << "double: nan" << std::endl;
	return ;
}

int	ScalarConverter::checkType(const std::string &input)
{
	char *ptr = NULL;
	std::strtod(input.c_str(), &ptr);
	if (input == "nanf" || input == "+inff" || input == "-inff" || input == "nan" || input == "+inf" || input == "-inf")
		return (0);
	if (ptr[0] == '\0' || (std::string(ptr) == "f" && input.size() != 1))
		return (1);
	else if (input.size() == 1 && std::isprint(input[0]))
		return (2);
	return (3);
}

void ScalarConverter::convert(const std::string input)
{
	double	value;

	char *ptr = NULL;
	value = strtod(input.c_str(), &ptr);

	if (checkType(input) == 3)
	{
		for (int i = 0; i < 4; i++)
			errorMessage(i);
	}
	if (checkType(input) == 0)
	{
		for (int i = 0; i < 2; i++)
			errorMessage(i);
		if (input == "nanf" || input == "nan")
		{
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		}
		else if (input == "+inff" || input == "+inf")
		{
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
		}
		else if (input == "-inff" || input == "-inf")
		{
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		}
	}

	if (checkType(input) == 2)
	{
		std::cout << "char: " << input[0] << std::endl;
		std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(input[0]) << "f" << std::endl;
		std::cout << "double: " << std::setprecision(1) << static_cast<double>(input[0]) << std::endl;
	}

	if (checkType(input) == 1)
	{
		if (value > 31 && value < 127)
			std::cout << "char: " << static_cast<char>(value) << std::endl;
		else if ((value >= 0 && value < 32) || (value >= 127 && value < 128))
			std::cout << "char: Non displayable" << std::endl;
		else
			errorMessage(0);
		if (value < 2147483648 && value > -2147483649)
			std::cout << "int: " << static_cast<int>(value) << std::endl;
		else
			errorMessage(1);
		std::cout << "float: ";
		if (static_cast<float>(value) == static_cast<int>(static_cast<float>(value)))
			std::cout << static_cast<float>(value) << ".0f" << std::endl;
		else
		 	std::cout << std::setprecision(std::numeric_limits<float>::digits10) << static_cast<float>(value) << "f" << std::endl;
		std::cout <<"double: ";
		if (value == static_cast<int>(value))
			std::cout << value << ".0" << std::endl;
		else
		 	std::cout << std::setprecision(std::numeric_limits<float>::digits10) << value << std::endl;
	}
}
