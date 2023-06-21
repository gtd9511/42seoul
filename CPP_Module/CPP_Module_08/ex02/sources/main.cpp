/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:44:49 by sanghan           #+#    #+#             */
/*   Updated: 2023/06/21 20:35:57 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"
#include <list>

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
	    std::cout << *it << std::endl;
		++it;
	}
	mstack.push(17);

	std::stack<int> s(mstack);

	std::cout << "---------------------" << std::endl;
	std::cout << "s.top() : " << s.top() << std::endl;
	std::cout << "mstack.top() : " << mstack.top() << std::endl;
	std::cout << "---------------------" << std::endl;

	std::cout << "list test (expected same output)" << std::endl;
	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);

	std::cout << lst.back() << std::endl;

	lst.pop_back();

	std::cout << lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator lstit = lst.begin();
	std::list<int>::iterator lstite = lst.end();

	++lstit;
	--lstit;
	while (lstit != lstite) {
		std::cout << *lstit << std::endl;
		++lstit;
	}
	lst.push_back(17);

	std::list<int> l(lst);

	std::cout << "---------------------" << std::endl;
	std::cout << "l.top() : " << l.back() << std::endl;
	std::cout << "lst.top() : " << lst.back() << std::endl;
	std::cout << "---------------------" << std::endl;
	return 0;
}
