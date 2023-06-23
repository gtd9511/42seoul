/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:43:14 by sanghan           #+#    #+#             */
/*   Updated: 2023/06/14 21:40:57 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"

int main(void)
{
	std::vector<int> v;
	std::list<int> l;
	std::deque<int> d;
	int i = 0;

	while (i < 10)
	{
		v.push_back(i);
		l.push_back(i);
		d.push_back(i);
		i++;
	}
	try
	{
		std::cout << *(easyfind(v, 3)) << std::endl;
		std::cout << *(easyfind(l, 5)) << std::endl;
		std::cout << *(easyfind(d, 7)) << std::endl;
		std::cout << *(easyfind(d, 10)) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
