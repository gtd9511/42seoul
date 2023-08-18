/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:49:04 by sanghan           #+#    #+#             */
/*   Updated: 2023/08/18 19:10:09 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <iomanip>

class PmergeMe
{
	private:
		size_t _size;
		std::vector<int> _v;
		std::deque<int> _d;
		int jacobsthal[31];

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &);
		PmergeMe &operator=(const PmergeMe &);

		bool getElement(int argc, char *argv);
		void setJacob();
		std::vector<int> vectorFJ();
		std::deque<int> dequeFJ();
		void printAfter();

};
#endif
