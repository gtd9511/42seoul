/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:04:38 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/08 21:13:33 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR;
	std::string &stringREF = str;
	stringPTR = &str;

	std::cout << str << std::endl
		<<	stringPTR << std::endl
		<<	&stringREF << std::endl
		<< std::endl << *stringPTR
		<< std::endl << stringREF << std::endl;

	return (0);
}
