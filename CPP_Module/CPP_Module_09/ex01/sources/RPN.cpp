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
	int i;
	double tempA;
	double tempB;

	i = 0;
	while (argv[i] != '\0')
	{
		if (isdigit(argv[i]))
			_stack.push(argv[i] - '0');
		else if (argv[i] == '+' || argv[i] == '-' || argv[i] == '*' || argv[i] == '/')
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

