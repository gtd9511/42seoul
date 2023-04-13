/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:43:14 by sanghan           #+#    #+#             */
/*   Updated: 2023/04/13 16:38:50 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "../includes/easyfind.hpp"

int main(void)
{
	std::vector<int> v;
	std::list<int> l;
	int i = 0;

	while (i < 10)
	{
		v.push_back(i);
		l.push_back(i);
		i++;
	}
	try
	{
		std::cout << easyfind(v, 5) << std::endl;
		std::cout << easyfind(l, 5) << std::endl;
		std::cout << easyfind(v, 10) << std::endl;
		std::cout << easyfind(l, 10) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Not found" << std::endl;
	}
	return 0;
}
