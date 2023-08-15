/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:49:04 by sanghan           #+#    #+#             */
/*   Updated: 2023/08/09 21:02:42 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <ctime>
// #include <iterator>
// #include <utility>
class PmergeMe
{
	private:
		size_t _size;
		std::vector<int> _v;
		std::list<int>	_l;
		std::deque<int> _d;
		int jacobsthal[31];
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &);
		PmergeMe &operator=(const PmergeMe &);

		bool getElement(int argc, char *argv);
		std::vector<int> vectorFJ();
		std::list<int> listFJ();
		std::deque<int> dequeFJ();
		void printAfter();

		template <typename T>
		void	FordJohnson(T container);
};
#endif
