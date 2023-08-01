#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <ctime>

class PmergeMe
{
	private:
		int	_size;
		std::vector<int> _vec;
		std::list<int>	_list;
		clock_t _vecStart;
		clock_t _vecEnd;
		clock_t _listStart;
		clock_t _listEnd;

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &);
		PmergeMe &operator=(const PmergeMe &);
		void	Pmerge(int argc, char**argv);
		void	checkArgs(int argc, char **args);
		void	sortSequence(std::vector<int> &);
		// void	sortSequence(std::list<int> &);
		void	getVectorList(int size, char** av);
		void	setVectorStartTime();
		void	setVectorEndTime();
		void	useVectorTime() const;
		void	insertionSortVector(int left, int right);
		void	sortVector();
		void	mergeVector(int l, int m, int r);
		void	mergeInsertionSortVector(int left, int right, int k);
		void 	printVector();

		void	listSort();
		int		getValueOfList(std::list<int> list, int idx);
		void	setValueOfList(int idx, int value);
		void	insertionSortList(int left, int right);
		void	mergeInsertionSortList(int left, int right, int k);
		void	mergeList(int l, int m, int r) ;
		void	setListStartTime();
		void	setListEndTime();
		void	useListTime() const;
		// void	printList();

};

#endif
