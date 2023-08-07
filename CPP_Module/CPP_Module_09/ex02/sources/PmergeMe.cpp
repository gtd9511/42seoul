/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:49:08 by sanghan           #+#    #+#             */
/*   Updated: 2023/08/07 19:25:04 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"
#include <iterator>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	if (this == &obj)
		return ;
	*this = obj;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &obj)
{
	if (this != &obj)
	{
		this->_d = obj._d;
		this->_v = obj._v;
		this->_l = obj._l;
	}
	return (*this);

}

void setjacobsthal()
{
	jacobsthal[0] = 1;
	jacobsthal[1] = 3;
	for (int i = 2; i < 20; i++)
		jacobsthal[i] = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
}

bool PmergeMe::getElement(char *argv)
{
	int temp = -1;
	int i = 0;
	while (argv[i] != '\0')
	{
		if (!isdigit(argv[i]))
			return (true);
		i++;
	}
	temp = atoi(argv);
	_v.push_back(temp);
	_l.push_back(temp);
	_d.push_back(temp);
	return (false);
}

std::vector<int> PmergeMe::vectorFJ()
{
	std::vector<std::pair<int, int> > vPair;
	std::vector<int> vResult;

	if (_v.size() == 1)
		return (vResult);

	return (vResult);
}

std::list<int> PmergeMe::listFJ()
{
	std::list<std::pair<int, int> > lPair;
	std::list<int> lResult;

	if (_l.size() == 1)
		return (lResult);

	return (lResult);
}

std::deque<int> PmergeMe::dequeFJ()
{
	std::deque<std::pair<int, int> > dPair;
	std::deque<int> dResult;

	if(_d.size() == 1)
		return (dResult);

	return (dResult);
}

template <typename T>
void printContainer(T container)
{
	typename T::iterator iter;

	for (iter = container.begin(); iter != container.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
}

void PmergeMe::printAfter()
{
	std::cout << "After with std::[Vector] : ";
	printContainer(_v);
	std::cout << "After with std::[List]   : ";
	printContainer(_l);
	std::cout << "After with std::[Deque]  : ";
	printContainer(_d);
}
