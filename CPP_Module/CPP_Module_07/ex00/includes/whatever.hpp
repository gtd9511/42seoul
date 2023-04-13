/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:37:47 by sanghan           #+#    #+#             */
/*   Updated: 2023/04/13 22:28:51 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T& min(T& a, T& b)
{
	if (a < b)
		return a;
	else
	 	return b;
}

template <typename T>
T& max(T& a, T& b)
{
	if (a > b)
		return a;
	else
	 	return b;
}

#endif
