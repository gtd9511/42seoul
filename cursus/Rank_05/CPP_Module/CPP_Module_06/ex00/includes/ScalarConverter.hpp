/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 08:40:47 by sanghan           #+#    #+#             */
/*   Updated: 2023/04/11 16:54:38 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ ScalarConverter();
	public:
		static void convert(const std::string input);
		static int	checkType(const std::string& input);
};

#endif
