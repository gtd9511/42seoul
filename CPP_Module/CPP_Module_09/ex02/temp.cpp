#include "includes/PmergeMe.hpp"

std::list<int> _l;

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
