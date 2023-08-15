/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:49:08 by sanghan           #+#    #+#             */
/*   Updated: 2023/08/15 20:20:03 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

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

bool PmergeMe::getElement(int argc, char *argv)
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

	_size = argc - 1;
	_v.push_back(temp);
	_l.push_back(temp);
	_d.push_back(temp);

	return (false);
}

bool compare(std::pair<int, int> a, std::pair<int, int> b)
{
	return a.second < b.second;
}

void PmergeMe::setJacob()
{
	jacobsthal[0] = 1;
	jacobsthal[1] = 3;
	for (int i = 2; i < 31; i++)
		jacobsthal[i] = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
}

// void binary_insertion(std::vector<int> &v)
// {
// 	int szie = v.size();
// 	// for (int i = 0; i < )
// }

std::vector<int> PmergeMe::vectorFJ()
{
	std::vector<std::pair<int, int> > vPair;
	std::vector<int> vResult;
	std::vector<int> aVec;
	std::vector<int> bVec;
	std::vector<int> execVec;
	int temp = 0;

	if (_v.size() == 1)
		return (_v);
	if (_v.size() % 2 != 0)
	{
		temp = _v.back();
		_v.pop_back();
	}
	for (size_t i = 0; i < _v.size(); i+= 2)
	{
		if (_v[i] > _v[i + 1])
			vPair.push_back(std::make_pair(_v[i], _v[i + 1]));
		else
		 	vPair.push_back(std::make_pair(_v[i + 1], _v[i]));
	}
	sort(vPair.begin(), vPair.end());
	vResult.push_back(vPair[0].second);
	for (std::vector<std::pair<int, int> >::iterator itr = vPair.begin(); itr != vPair.end(); itr++)
	{
		// std::cout << itr->first << " " << itr->second << std::endl;
		vResult.push_back(itr->first);
		aVec.push_back(itr->first);
		bVec.push_back(itr->second);
	}
	if (temp)
		bVec.push_back(temp);
	// std::cout << "a : ";
	// for (std::vector<int>::iterator itr = aVec.begin(); itr != aVec.end(); itr++)
	// 	std::cout << *itr << " ";
	// std::cout << std::endl << "b : ";
	// for (std::vector<int>::iterator itr = bVec.begin(); itr != bVec.end(); itr++)
	// 	std::cout << *itr << " ";
	// std::cout << std::endl << "result : ";
	// for (std::vector<int>::iterator itr = vResult.begin(); itr != vResult.end(); itr++)
	// 	std::cout << *itr << " ";

	// std::cout << std::endl << "*******************" << std::endl;
	int bsize = bVec.size();
	// std::cout << jacobsthal[1] << "\n";
	// std::cout << bsize << "\n";
	int jacobIdx = 0;
	int nearJacob = 0;
	while (jacobsthal[jacobIdx] <= bsize)
	{
		if (jacobIdx > 0)
		{
			int execIdx = jacobsthal[jacobIdx];
			nearJacob = jacobsthal[jacobIdx];
			while (execIdx > jacobsthal[jacobIdx - 1])
				execVec.push_back(execIdx--);
		}
		jacobIdx++;
	}
	while (bsize > nearJacob)
		execVec.push_back(bsize--);
	std::cout << std::endl;
	for (int i = 0; i < static_cast<int>(execVec.size()); i++)
	{
		// std::cout << "실행 차례 : " << execVec[i] << std::endl;
		// std::cout << "처음 묶인 a : " << aVec[execVec[i] - 1] << std::endl;
		// std::cout << "이번에 들어갈 b : " << bVec[execVec[i] - 1] << std::endl;
		int maxIdx = 0;
		for (int j = 0; j < static_cast<int>(vResult.size()); j++)
		{
			if (aVec[execVec[i] - 1] == vResult[j])
				maxIdx = j;
		}
		// std::cout << "maxIdx : " << vResult[maxIdx] << std::endl;
		int lo = 0;
		int hi = maxIdx;
		int mid;
		// std::cout << "high : " << hi << std::endl;
		while (lo < hi)
		{
			mid = (lo + hi) / 2;

			if (bVec[execVec[i] - 1] < vResult[mid])
				hi = mid;
			else
				lo = mid + 1;
		}
		// std::cout << "lo : " << lo << " " << vResult[lo] << std::endl;
		// std::cout << "mid : " << mid << " " << vResult[mid] << std::endl;
		// std::cout << "hi : " << hi << " " << vResult[hi] << std::endl;
		// std::cout << *(vResult.begin() + mid) << std::endl;
		if (lo == mid)
			vResult.insert(vResult.begin() + mid, bVec[execVec[i] - 1]);
		else
		 	vResult.insert(vResult.begin() + mid + 1, bVec[execVec[i] - 1]);
		// std::cout << "result :";
		// for (int j = 0; j < static_cast<int>(vResult.size()); j++)
			// std::cout << vResult[j] << " ";
		// std::cout << std::endl;
		// std::cout << std::endl;
	}
	std::cout << std::endl;

	// std::cout << "*******************" << std::endl;

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
	typename T::iterator itr;

	for (itr = container.begin(); itr != container.end(); itr++)
		std::cout << *itr << " ";
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
