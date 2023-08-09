/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:48:48 by sanghan           #+#    #+#             */
/*   Updated: 2023/08/09 15:40:17 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <string>

class RPN
{
	private:
		std::string _argv;
		std::stack<double> _stack;
	public:
		RPN();
		RPN(char* argv);
		~RPN();
		RPN(const RPN &obj);
		RPN &operator=(RPN const &obj);

		bool calculateRPN(char* argv);
};

#endif
