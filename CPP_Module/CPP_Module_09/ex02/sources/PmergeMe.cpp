/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:49:08 by sanghan           #+#    #+#             */
/*   Updated: 2023/08/17 23:31:44 by sanghan          ###   ########.fr       */
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

void PmergeMe::setJacob()
{
	jacobsthal[0] = 1;
	jacobsthal[1] = 3;
	for (int i = 2; i < 31; i++)
		jacobsthal[i] = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
}

std::vector<int> PmergeMe::vectorFJ()
{
	std::vector<std::pair<int, int> > vPair;
	std::vector<int> vResult;
	std::vector<int> aVec;
	std::vector<int> bVec;
	std::vector<int> execVec;
	int is_odd = 0;

	if (_v.size() == 1)
		return (_v);
	if (_v.size() % 2 != 0)
	{
		is_odd = _v.back();
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
		vResult.push_back(itr->first);
		aVec.push_back(itr->first);
		bVec.push_back(itr->second);
	}
	// if (is_odd)
	// 	bVec.push_back(is_odd);

	// std::cout << "A vec : ";
	// for (int i = 0; i < static_cast<int>(aVec.size()); i++)
	// 	std::cout << aVec[i] << " ";
	// std::cout << std::endl << "B vec : ";
	// for (int i = 0; i < static_cast<int>(bVec.size()); i++)
	// 	std::cout << bVec[i] << " ";
	// std::cout << std::endl << "v Res : ";
	// for (int i = 0; i < static_cast<int>(vResult.size()); i++)
	// 	std::cout << vResult[i] << " ";
	// std::cout << std::endl;

	int bsize = bVec.size();
	int jacobIdx = 0;
	int nearJacob = 0;
	// std::cout << "exec : ";
	// for (int i = 0; i < static_cast<int>(execVec.size()); i++)
	// 	std::cout << execVec[i] << " ";
	// std::cout << std::endl;
	//완전 야곱 수인 경우
	while (jacobsthal[jacobIdx] <= bsize)
	{
		// if (jacobIdx > 0)
		// {
			int execIdx = jacobsthal[jacobIdx];
			nearJacob = jacobsthal[jacobIdx];
			while (execIdx > jacobsthal[jacobIdx - 1])
				execVec.push_back(execIdx--);
		// }
		jacobIdx++;
	}
	// std::cout << "exec2 : ";
	// for (int i = 0; i < static_cast<int>(execVec.size()); i++)
	// 	std::cout << execVec[i] << " ";
	// std::cout << std::endl;
	// std::cout << "bsize : " << bsize << std::endl;
	// std::cout << "nearJacob : " << nearJacob << std::endl;
	// if (bsize == 2)
	// 	execVec.push_back(2);
	// while (bsize > nearJacob && bsize > 2)
	//완전 야곱 수가 아닌 경우
	while (bsize > nearJacob)
		execVec.push_back(bsize--);
	int eVec_Size = execVec.size();
	int vRes_Size = vResult.size();
	// std::cout << "exec : ";
	// for (int i = 0; i < eVec_Size; i++)
	// 	std::cout << execVec[i] << " ";
	// std::cout << std::endl;
	// std::cout << std::endl << "vR : ";
	// for (int i = 0; i < static_cast<int>(vResult.size()); i++)
	// 	std::cout << vResult[i] << " ";
	// std::cout << std::endl;
	// std::cout << "A : " << vRes_Size << std::endl;
	for (int i = 0; i < eVec_Size; i++)
	{
		int maxIdx = 0;

		// for (int j = 0; j < static_cast<int>(vResult.size()); j++)
		if (execVec[i] != 1)
		{
			for (int j = 0; j < vRes_Size; j++)
			{
				if (aVec[execVec[i] - 1] == vResult[j])
					maxIdx = j;
			}
			// std::cout << "maxIDX : " << maxIdx << std::endl;
			int lo = 0;
			int hi = maxIdx;
			// int mid;
			while (lo < hi)
			{
				int mid = (lo + hi) / 2;

				if (bVec[execVec[i] - 1] < vResult[mid])
					hi = mid;
				else
					lo = mid + 1;
			}
			// std::cout << "l : " << lo << " m : " << (lo + hi) / 2 << " h : " << hi << std::endl;
			// std::cout << mid << std::endl;
			if (lo == (lo + hi) / 2)
				vResult.insert(vResult.begin() + (lo + hi) / 2, bVec[execVec[i] - 1]);
			else
			 	vResult.insert(vResult.begin() + (lo + hi) / 2 + 1, bVec[execVec[i] - 1]);
			// if (lo == mid)
			// 	vResult.insert(vResult.begin() + mid, bVec[execVec[i] - 1]);
			// else
			//  	vResult.insert(vResult.begin() + mid + 1, bVec[execVec[i] - 1]);
			// for (int i = 0; i < static_cast<int>(vResult.size()); i++)
			// 	std::cout << vResult[i] << " ";
			// std::cout << std::endl;
			// std::cout << "is_odd : " << is_odd	 << std::endl;
		}
	}
	if (is_odd)
		{
			int lo = 0;
			int hi = vResult.size();
			while (lo < hi)
			{
				int mid = (lo + hi) / 2;

				if (is_odd < vResult[mid])
					hi = mid;
				else
					lo = mid + 1;
			}
			if (lo == (lo + hi) / 2)
				vResult.insert(vResult.begin() + (lo + hi) / 2, is_odd);
			else
			 	vResult.insert(vResult.begin() + (lo + hi) / 2 + 1, is_odd);
		}
	_v = vResult;
	return (_v);
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
	// std::cout << "After with std::[List]   : ";
	// printContainer(_l);
	// std::cout << "After with std::[Deque]  : ";
	// printContainer(_d);
}
