/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:44:36 by sanghan           #+#    #+#             */
/*   Updated: 2023/07/06 20:30:31 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include <algorithm>

Span::Span(unsigned int N)
{
	this->N_ = N;
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
	this->N_ = span.N_;
	this->V_ = span.V_;
	return (*this);
}

void Span::addNumber(int n)
{
	if (this->V_.size() == this->N_)
		throw Span::FullException();
	this->V_.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (std::distance(begin, end) + V_.size() > N_)
		throw Span::NoSpanException();
	V_.insert(V_.end(), begin, end);
}

size_t Span::shortestSpan()
{
	if (this->V_.size() <= 1)
		throw Span::NoSpanException();
	std::vector<int> v = this->V_;
	std::sort(v.begin(), v.end());
	size_t min = static_cast<size_t>(v[1]) - static_cast<size_t>(v[0]);
	for (unsigned int i = 2; i < v.size(); i++)
	{
		size_t temp = static_cast<size_t>(v[i]) - static_cast<size_t>(v[i - 1]);
		if (temp < min)
			min = temp;
	}
	return (min);
}

size_t Span::longestSpan()
{
	if (this->V_.size() <= 1)
		throw Span::NoSpanException();
	std::vector<int> v = this->V_;
	std::sort(v.begin(), v.end());
	return(static_cast<size_t>(v[v.size() - 1]) - static_cast<size_t>(v[0]));
}

const char *Span::FullException::what() const throw()
{
	return ("Span is full");
}

const char *Span::NoSpanException::what() const throw()
{
	return ("Span is too small");
}

