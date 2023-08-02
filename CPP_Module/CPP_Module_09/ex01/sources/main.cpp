/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:48:54 by sanghan           #+#    #+#             */
/*   Updated: 2023/08/02 21:59:01 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

// void leaks()
// {
// 	system("leaks RPN");
// }

int main(int argc, char* argv[])
{
	// atexit(leaks);
	if (argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return (0);
	}
	RPN rpn(argv[1]);
	if (rpn.calculateRPN(argv[1]))
	{
		std::cerr << "Error" << std::endl;
		return (0);
	}
	return (0);
}


