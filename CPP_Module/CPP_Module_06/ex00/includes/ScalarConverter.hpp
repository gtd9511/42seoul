/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 08:40:47 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/29 08:42:45 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
//#include <iomanip>
//#include <cmath>

class ScalarConverter
{
	private:
		ScalarConverter(void);

	public:
		~ScalarConverter(void);
		ScalarConverter(const ScalarConverter& obj);
		ScalarConverter& operator=(const ScalarConverter& obj);

		static void convert(const std::string& input);
};

#endif
