/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:49:04 by sanghan           #+#    #+#             */
/*   Updated: 2023/08/03 17:00:21 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <ctime>

class PmergeMe
{
	private:
		std::vector<int> _v;
		std::list<int>	_l;
		std::deque<int> _d;
		clock_t _vStart;
		clock_t _vEnd;
		clock_t _lStart;
		clock_t _lEnd;
		clock_t _dStart;
		clock_t _dEnd;
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &);
		PmergeMe &operator=(const PmergeMe &);
};

#endif
