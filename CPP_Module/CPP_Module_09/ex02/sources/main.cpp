/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:49:07 by sanghan           #+#    #+#             */
/*   Updated: 2023/08/18 19:10:25 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int main(int argc, char* argv[])
{
	PmergeMe	PM;
	time_t 		start, end;
	double		vec_time, deque_time;
	bool		noError = true;

	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return (0);
	}
	PM.setJacob();
	int i = 1;
	while (i < argc)
	{
		if (PM.getElement(argc, argv[i]))
		{
			noError = false;
			break;
		}
		i++;
	}
	if (noError)
	{
		std:: cout << "Before:	";
		for (int i = 1; i < argc; i++)
			std::cout << argv[i] << " ";
		std::cout << std::endl;

		start = clock();
		PM.vectorFJ();
		end = clock();
		vec_time = (double)(end - start) / CLOCKS_PER_SEC * 1000;

		start = clock();
		PM.dequeFJ();
		end = clock();
		deque_time = (double)(end - start) / CLOCKS_PER_SEC * 1000;

		PM.printAfter();
		std::cout << std::fixed << std::setprecision(4);
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::[Vector] : " << vec_time << " ms" << std::endl;
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::[Deque]  : " << deque_time << " ms" << std::endl;
	}
	else
		std::cerr << "Error" << std::endl;
	return (0);
}
