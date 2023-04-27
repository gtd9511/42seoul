/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:38:07 by sanghan           #+#    #+#             */
/*   Updated: 2023/04/27 17:50:01 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(const T *array, size_t len, void (*fn)(const T&)) {
	for (size_t i = 0; i < len; i++)
		fn(array[i]);
}

template <typename T>
void print(const T& a) {
	std::cout << a << " ";
}
#endif
