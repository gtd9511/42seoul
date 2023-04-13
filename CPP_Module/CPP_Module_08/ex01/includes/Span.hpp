/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:44:31 by sanghan           #+#    #+#             */
/*   Updated: 2023/04/13 16:42:50 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class Span
{
	private:
		unsigned int _N;
		std::vector<int> _V;
		Span();
	public:
		Span(unsigned int n);
		Span(const Span &copy);
		Span &operator=(const Span &assign);
		~Span();
		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		class FullException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class NoSpanException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
