/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:44:36 by sanghan           #+#    #+#             */
/*   Updated: 2023/06/15 09:58:31 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

Span::Span(unsigned int N)
{
	this->_N = N;
}

Span::~Span()
{
}

Span::Span(Span const &span)
{
	*this = span;
}

Span &Span::operator=(Span const &span)
{
	this->_N = span._N;
	this->_V = span._V;
	return (*this);
}

void Span::addNumber(int n)
{
	if (this->_V.size() == this->_N)
		throw Span::FullException();
	this->_V.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (std::distance(begin, end) > _N)
		throw Span::NoSpanException();
	_V.insert(_V.end(), begin, end);
}

int Span::shortestSpan()
{
	if (this->_V.size() <= 1)
		throw Span::NoSpanException();
	std::vector<int> v = this->_V;
	std::sort(v.begin(), v.end());
	int min = v[1] - v[0];
	for (unsigned int i = 2; i < v.size(); i++)
	{
		if (v[i] - v[i - 1] < min)
			min = v[i] - v[i - 1];
	}
	return (min);
}

int Span::longestSpan()
{
	if (this->_V.size() <= 1)
		throw Span::NoSpanException();
	std::vector<int> v = this->_V;
	std::sort(v.begin(), v.end());
	return (v[v.size() - 1] - v[0]);
}

const char *Span::FullException::what() const throw()
{
	return ("Span is full");
}

const char *Span::NoSpanException::what() const throw()
{
	return ("Span is too small");
}

