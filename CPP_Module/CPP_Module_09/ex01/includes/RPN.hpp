/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:48:48 by sanghan           #+#    #+#             */
/*   Updated: 2023/08/02 21:57:51 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>

class RPN
{
	private:
		std::string _argv;
	public:
		std::stack<double> _stack;

		RPN();
		RPN(char* argv);
		~RPN();
		RPN(const RPN &obj);
		RPN &operator=(RPN const &obj);

		bool calculateRPN(char* argv);
};

#endif
