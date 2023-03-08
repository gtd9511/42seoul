/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:04:38 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/08 21:27:15 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR;
	std::string &stringREF = str;
	stringPTR = &str;

	std::cout << "string address        : " << &str << std::endl
		<<	"string address by ptr : " << stringPTR << std::endl
		<<	"string address by ref : " << &stringREF << std::endl
		<< std::endl << "stirng value        : " << str << std::endl
		<< "string value by ptr : " << *stringPTR << std::endl
		<< "string value by ref : " << stringREF << std::endl;

	return (0);
}
