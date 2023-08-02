/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:48:52 by sanghan           #+#    #+#             */
/*   Updated: 2023/08/02 22:04:15 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"
#include <iostream>

RPN::RPN() {}

RPN::RPN(char* argv)
{
	this->_argv = argv;
}

RPN::~RPN() {}

RPN::RPN(const RPN &obj)
{
	if (this == &obj)
		return ;
	*this = obj;
}

RPN& RPN::operator=(RPN const &obj)
{
	if (this != &obj)
		this->_argv = obj._argv;
	return (*this);
}

bool RPN::calculateRPN(char* argv)
{
	std::stack<double> stack;
	int i;
	double tempA;
	double tempB;

	i = 0;
	while (argv[i] != '\0')
	{
		if (isdigit(argv[i]))
			stack.push(argv[i] - '0');
		else if (argv[i] == '+' || argv[i] == '-' || argv[i] == '*' || argv[i] == '/')
		{
			if (stack.size() < 2)
			{
				std::cout << "B" << std::endl;
				return (true);
			}
			tempB = stack.top();
			stack.pop();
			tempA = stack.top();
			stack.pop();
			if (argv[i] == '+')
				stack.push(tempA + tempB);
			else if (argv[i] == '-')
				stack.push(tempA - tempB);
			else if (argv[i] == '*')
				stack.push(tempA * tempB);
			else if (argv[i] == '/')
				stack.push(tempA / tempB);
		}
		else if (argv[i] != ' ')
			return (true);
		i++;
	}
	if (stack.size() == 1)
	{
		std::cout << stack.top() << std::endl;
		return (false);
	}
	else
		return (true);
}

