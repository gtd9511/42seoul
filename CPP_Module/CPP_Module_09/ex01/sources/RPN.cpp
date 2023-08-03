/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:48:52 by sanghan           #+#    #+#             */
/*   Updated: 2023/08/03 16:14:09 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

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
	int i = 0;
	double tempA, tempB;

	while (argv[i] != '\0')
	{
		if (isdigit(argv[i]) && (argv[i + 1] == ' '))
			_stack.push(argv[i] - '0');
		else if ((argv[i] == '+' || argv[i] == '-' || argv[i] == '*' || argv[i] == '/') && (argv[i + 1] == ' ' || argv[i + 1] == '\0'))
		{
			if (_stack.size() < 2)
				return (true);
			tempB = _stack.top();
			_stack.pop();
			tempA = _stack.top();
			_stack.pop();
			if (argv[i] == '+')
				_stack.push(tempA + tempB);
			else if (argv[i] == '-')
				_stack.push(tempA - tempB);
			else if (argv[i] == '*')
				_stack.push(tempA * tempB);
			else if (argv[i] == '/')
			{
				if (tempB == 0)
					return (true);
				_stack.push(tempA / tempB);
			}
		}
		else if (argv[i] != ' ')
			return (true);
		i++;
	}
	if (_stack.size() == 1)
	{
		std::cout << _stack.top() << std::endl;
		return (false);
	}
	else
		return (true);
}

