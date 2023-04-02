/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 08:40:46 by sanghan           #+#    #+#             */
/*   Updated: 2023/04/02 21:00:46 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

void ScalarConverter::convert(const std::string input)
{
	double	dvalue;
	float	fvalue;
	int	ivalue;

	char *ptr = NULL;
	dvalue = strtod(input.c_str(), &ptr);



	std::cout << "char: ";
	if (ivalue > 31 && ivalue < 127)
		std::cout << static_cast<char>(ivalue) << std::endl;
	else if ((ivalue >= 0 && ivalue < 32) || ivalue == 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "int: " << std::endl;
	if (dvalue < 2147483648 && dvalue > -2147483649)
		std::cout << static_cast<int>(dvalue) << std::endl;
	else
	 	std::cout << "impossible" << std::endl;

	std::cout << "float: " << std::endl;

	std::cout << "double: " << std::endl;
}

//a~z

//0~127
