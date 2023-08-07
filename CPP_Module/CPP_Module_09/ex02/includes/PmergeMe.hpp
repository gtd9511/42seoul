/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:49:04 by sanghan           #+#    #+#             */
/*   Updated: 2023/08/07 19:24:56 by sanghan          ###   ########.fr       */
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
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &);
		PmergeMe &operator=(const PmergeMe &);

		bool getElement(char *argv);
		std::vector<int> vectorFJ();
		std::list<int> listFJ();
		std::deque<int> dequeFJ();
		void printAfter();
};
#endif
