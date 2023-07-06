/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:44:34 by sanghan           #+#    #+#             */
/*   Updated: 2023/07/06 20:34:47 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

int main(void)
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span sp2 = Span(20000);

	std::vector<int> vec;
	for (int i = 0; i < 20000; i++)
		vec.push_back(2 * i);

	sp2.addNumber(vec.begin(), vec.end());

	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	Span sp3 = Span(2);
	sp3.addNumber(-2147483648);
	sp3.addNumber(2147483647);

	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;

	Span sp4 = Span(5);
	sp4.addNumber(-2147483648);
	sp4.addNumber(2147483647);
	sp4.addNumber(17);
	sp4.addNumber(9);
	sp4.addNumber(11);

	std::cout << sp4.shortestSpan() << std::endl;
	std::cout << sp4.longestSpan() << std::endl;

	Span sp5 = Span(11);

	sp5.addNumber(1);
	sp5.addNumber(5);
	std::vector<int> vec2;
	for (int i = 0; i < 10; i++)
		vec2.push_back(i);
	sp5.addNumber(vec2.begin(), vec2.end());

	return 0;
}
