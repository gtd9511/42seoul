/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:44:36 by sanghan           #+#    #+#             */
/*   Updated: 2023/06/23 16:59:46 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

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
	if (std::distance(begin, end) > N_)
		throw Span::NoSpanException();
	V_.insert(V_.end(), begin, end);
}

long Span::shortestSpan()
{
	if (this->V_.size() <= 1)
		throw Span::NoSpanException();
	std::vector<int> v = this->V_;
	std::sort(v.begin(), v.end());
	long min = static_cast<long>(v[1]) - static_cast<long>(v[0]);
	for (unsigned int i = 2; i < v.size(); i++)
	{
		long temp = static_cast<long>(v[i]) - static_cast<long>(v[i - 1]);
		if (temp < min)
			min = temp;
	}
	return (min);
}

long Span::longestSpan()
{
	if (this->V_.size() <= 1)
		throw Span::NoSpanException();
	std::vector<int> v = this->V_;
	std::sort(v.begin(), v.end());
	long max = static_cast<long>(v[v.size() - 1]) - static_cast<long>(v[0]);
	return (max);
}

const char *Span::FullException::what() const throw()
{
	return ("Span is full");
}

const char *Span::NoSpanException::what() const throw()
{
	return ("Span is too small");
}

