#include "PmergeMe.hpp"
PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& origin)
{
	*this = origin;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& origin)
{
	if (this != &origin)
	{
		this->_vec = origin._vec;
		this->_list = origin._list;
	}
	return *this;
}

void	PmergeMe::Pmerge(int argc, char**argv)
{
	getVectorList(argc, argv);
	sortVector();
	listSort();
}


void PmergeMe::getVectorList(int size, char **argv) {
	std::cout << "Before:";
	for (int i = 1; i < size; i++) {
		int num =  atoi(argv[i]);
		std::cout << " " << num;
		if (i == size - 1)
			std::cout << std::endl;
		_vec.push_back(num);
		_list.push_back(num);
		_size = size-1;

	}
}

void PmergeMe::sortVector() {
	setVectorStartTime();
	mergeInsertionSortVector(0, this->_vec.size() - 1, this->_vec.size() / 2);
	setVectorEndTime();
	printVector();
	useVectorTime();
}

void PmergeMe::insertionSortVector(int left, int right)
{
	for (int i = left + 1; i <= right; i++)
	{
		int key = this->_vec[i];
		int j = i - 1;
		while (j >= left && this->_vec[j] > key)
		{
			this->_vec[j + 1] = this->_vec[j];
			j--;
		}
		this->_vec[j + 1] = key;
	}
}

void PmergeMe::mergeVector(int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;

	std::vector<int> left(n1), right(n2);

	for (int i = 0; i < n1; i++)
		left[i] = this->_vec[l + i];
	for (int j = 0; j < n2; j++)
		right[j] = this->_vec[m + 1 + j];

	int i = 0;
	int j = 0;
	int k = l;

	while (i < n1 && j < n2)
	{
		if (left[i] <= right[j])
		{
		this->_vec[k] = left[i];
		i++;
		}
		else
		{
		this->_vec[k] = right[j];
		j++;
		}
		k++;
	}

	while (i < n1)
	{
		this->_vec[k] = left[i];
		i++;
		k++;
	}

	while (j < n2) {
		this->_vec[k] = right[j];
		j++;
		k++;
	}
}

void PmergeMe::mergeInsertionSortVector(int left, int right, int k) {
	if (right - left + 1 <= k)
	{
		insertionSortVector(left, right);
	}
	else if (left < right)
	{
		int m = left + (right - left) / 2;
		mergeInsertionSortVector(left, m, k);
		mergeInsertionSortVector(m + 1, right, k);
		mergeVector(left, m, right);
  }
}

void PmergeMe::setVectorStartTime() {
	_vecStart = clock();

}

void PmergeMe::setVectorEndTime() {
	_vecEnd = clock();
}

void PmergeMe::useVectorTime() const {
	double time = _vecEnd - _vecStart;
	std::cout << "Time to process a range of " << _size << " elements with " << "std::[vector]: " << time << "ms" << std::endl;
}

void PmergeMe::setListStartTime() {
	_listStart = clock();

}

void PmergeMe::setListEndTime() {
	_listEnd = clock();
}

void PmergeMe::useListTime() const {
	double time = _listEnd - _listStart;
	std::cout << "Time to process a range of " << _size << " elements with " << "std::[List]: " << time << "ms" << std::endl;
}


void PmergeMe::printVector() {
	std::cout <<"Vector After:" ;
	for (int i = 0; i < _size; i++)
		std::cout << " " << _vec[i];
	std::cout << std::endl;
}

int PmergeMe::getValueOfList(std::list<int> list, int idx)
{
	std::list<int> tmpList;

	tmpList.assign(list.begin(), list.end());
	std::list<int>::iterator iter = tmpList.begin();
	while (idx--)
		++iter;
	return *iter;
}

void PmergeMe::setValueOfList(int idx, int value)
{
	std::list<int>::iterator iter = this->_list.begin();
	while (idx--)
		++iter;
	*iter = value;
}

void PmergeMe::listSort()
{
	setListStartTime();
	mergeInsertionSortList(0, this->_list.size() - 1, 5);//this->_list.size() / 2
	setListEndTime();
	// printList();
	useListTime();
}

void PmergeMe::insertionSortList(int left, int right) {
	for (int i = left + 1; i <= right; i++)
	{
		int key = this->getValueOfList(this->_list, i);
		int j = i - 1;
		while (j >= left && this->getValueOfList(this->_list, j) > key)
		{
			this->setValueOfList(j + 1, this->getValueOfList(this->_list, j));
			j--;
		}
		this->setValueOfList(j + 1, key);
	}
}

void PmergeMe::mergeList(int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	std::list<int> left, right;

	for (int i = 0; i < n1; i++) left.push_back(this->getValueOfList(this->_list, l + i));
	for (int j = 0; j < n2; j++) right.push_back(this->getValueOfList(this->_list, m + 1 + j));

	int i = 0;
	int j = 0;
	int k = l;

	while (i < n1 && j < n2)
	{
		if (this->getValueOfList(left, i) <= this->getValueOfList(right, j)) {
		this->setValueOfList(k, this->getValueOfList(left, i));
		i++;
		} else {
		this->setValueOfList(k, this->getValueOfList(right, j));
		j++;
		}
		k++;
	}

	while (i < n1) {
		this->setValueOfList(k, this->getValueOfList(left, i));
		i++;
		k++;
	}

	while (j < n2) {
		this->setValueOfList(k, this->getValueOfList(right, j));
		j++;
		k++;
	}
}

void PmergeMe::mergeInsertionSortList(int left, int right, int k) {
	if (right - left + 1 <= k) {
		insertionSortList(left, right);
	} else if (left < right) {
		int m = left + (right - left) / 2;
		mergeInsertionSortList(left, m, k);
		mergeInsertionSortList(m + 1, right, k);
		mergeList(left, m, right);
	}
}


// void PmergeMe::printList() {
// 	std::cout <<"List After:" ;

// 	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++)
// 	{
// 		std::cout << " " << *it;
// 	}
// 	std::cout << std::endl;
// }
