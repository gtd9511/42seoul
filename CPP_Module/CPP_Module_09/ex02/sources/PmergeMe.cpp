/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:49:08 by sanghan           #+#    #+#             */
/*   Updated: 2023/08/18 00:01:03 by sanghan          ###   ########.fr       */
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
		// this->_l = obj._l;
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
	// _l.push_back(temp);
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

	int aVecSize = aVec.size();
	int bVecSize = bVec.size();
	int vResultSize = vResult.size();

	std::cout << "A vec : ";
	for (int i = 0; i < aVecSize; i++)
		std::cout << aVec[i] << " ";
	std::cout << std::endl;

	std::cout << "B vec : ";
	for (int i = 0; i < bVecSize; i++)
		std::cout << bVec[i] << " ";
	std::cout << std::endl;

	std::cout << "V res : ";
	for (int i = 0; i < vResultSize; i++)
		std::cout << vResult[i] << " ";
	std::cout << std::endl;

	int bsize = bVec.size();
	int jacobIdx = 0;
	int nearJacob = 0;

	//완전 야곱 수인 경우
	while (jacobsthal[jacobIdx] <= bsize)
	{
			int execIdx = jacobsthal[jacobIdx];
			nearJacob = jacobsthal[jacobIdx];
			while (execIdx > jacobsthal[jacobIdx - 1])
				execVec.push_back(execIdx--);
		jacobIdx++;
	}
	//완전 야곱 수가 아닌 경우
	while (bsize > nearJacob)
		execVec.push_back(bsize--);
	int eVec_Size = execVec.size();
	// int vRes_Size = vResult.size();

	std::cout << "Exec vec : ";
	for (int i = 0; i < eVec_Size; i++)
		std::cout << execVec[i] << " ";
	std::cout << std::endl;

	for (int i = 0; i < eVec_Size; i++)
	{
		int maxIdx = 0;
		// if (i == 3)
			// std::cout << "Exec vec : " << execVec[i] << std::endl;
		if (execVec[i] != 1)
		{
			for (int j = 0; j < static_cast<int>(vResult.size()); j++)
			{
				if (aVec[execVec[i] - 1] == vResult[j])
					maxIdx = j;
			}
			std::cout << "maxIdx : " << maxIdx << std::endl;
			int lo = 0;
			int hi = maxIdx;
			while (lo < hi)
			{
				int mid = (lo + hi) / 2;

				if (bVec[execVec[i] - 1] < vResult[mid])
					hi = mid;
				else
					lo = mid + 1;
			}
			if (lo == (lo + hi) / 2)
				vResult.insert(vResult.begin() + (lo + hi) / 2, bVec[execVec[i] - 1]);
			else
			 	vResult.insert(vResult.begin() + (lo + hi) / 2 + 1, bVec[execVec[i] - 1]);
		}
		std::cout << "V res : ";
		for (int i = 0; i < static_cast<int>(vResult.size()); i++)
			std::cout << vResult[i] << " ";
		std::cout << std::endl;
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

std::deque<int> PmergeMe::dequeFJ()
{
	std::deque<std::pair<int, int> > dPair;
	std::deque<int> dResult;
	std::deque<int> aDeq;
	std::deque<int> bDeq;
	std::deque<int> execDeq;
	int is_odd = 0;

	if (_d.size() == 1)
		return (_d);
	if (_d.size() % 2 != 0)
	{
		is_odd = _d.back();
		_d.pop_back();
	}
	for (size_t i = 0; i < _d.size(); i+= 2)
	{
		if (_d[i] > _d[i + 1])
			dPair.push_back(std::make_pair(_d[i], _d[i + 1]));
		else
		 	dPair.push_back(std::make_pair(_d[i + 1], _d[i]));
	}
	sort(dPair.begin(), dPair.end());

	dResult.push_back(dPair[0].second);
	for (std::deque<std::pair<int, int> >::iterator itr = dPair.begin(); itr != dPair.end(); itr++)
	{
		dResult.push_back(itr->first);
		aDeq.push_back(itr->first);
		bDeq.push_back(itr->second);
	}

	int bsize = bDeq.size();
	int jacobIdx = 0;
	int nearJacob = 0;

	//완전 야곱 수인 경우
	while (jacobsthal[jacobIdx] <= bsize)
	{
			int execIdx = jacobsthal[jacobIdx];
			nearJacob = jacobsthal[jacobIdx];
			while (execIdx > jacobsthal[jacobIdx - 1])
				execDeq.push_back(execIdx--);
		jacobIdx++;
	}
	//완전 야곱 수가 아닌 경우
	while (bsize > nearJacob)
		execDeq.push_back(bsize--);
	int eVec_Size = execDeq.size();
	int vRes_Size = dResult.size();
	for (int i = 0; i < eVec_Size; i++)
	{
		int maxIdx = 0;

		if (execDeq[i] != 1)
		{
			for (int j = 0; j < vRes_Size; j++)
			{
				if (aDeq[execDeq[i] - 1] == dResult[j])
					maxIdx = j;
			}
			int lo = 0;
			int hi = maxIdx;
			while (lo < hi)
			{
				int mid = (lo + hi) / 2;

				if (bDeq[execDeq[i] - 1] < dResult[mid])
					hi = mid;
				else
					lo = mid + 1;
			}
			if (lo == (lo + hi) / 2)
				dResult.insert(dResult.begin() + (lo + hi) / 2, bDeq[execDeq[i] - 1]);
			else
			 	dResult.insert(dResult.begin() + (lo + hi) / 2 + 1, bDeq[execDeq[i] - 1]);
		}
	}
	if (is_odd)
		{
			int lo = 0;
			int hi = dResult.size();
			while (lo < hi)
			{
				int mid = (lo + hi) / 2;

				if (is_odd < dResult[mid])
					hi = mid;
				else
					lo = mid + 1;
			}
			if (lo == (lo + hi) / 2)
				dResult.insert(dResult.begin() + (lo + hi) / 2, is_odd);
			else
			 	dResult.insert(dResult.begin() + (lo + hi) / 2 + 1, is_odd);
		}
	_d = dResult;
	return (_d);
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
	std::cout << "After with std::[Deque]  : ";
	printContainer(_d);
}
