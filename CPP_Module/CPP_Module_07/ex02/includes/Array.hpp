/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:38:13 by sanghan           #+#    #+#             */
/*   Updated: 2023/04/02 21:16:53 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T* _array;
		unsigned int _arraySize;

	public:
		Array() :_array(new T), _arraySize(0){}
		Array(unsigned int n) : _array(new T[n]), _arraySize(n){}
		Array(const Array &origin)
		{
			this->_array = new T[origin._arraySize];
			this->_arraySize = origin._arraySize;
		}

	Array &operator=(const Array &origin)
	{
		if (this != &origin)
		{
			delete this->_array;
			this->_array = new T[origin._arraySize];
			this->_arraySize = origin._arraySize;
			for (unsigned int i = 0; i < this->_arraySize; i++)
				this->arr[i] = origin.arr[i];
		}
		return *this;
	}

	~Array()
	{
		  if (this->_arraySize != 0)
			delete [] this->_array;
		this->_array = NULL;
		this->_arraySize = 0;
	}

	T& operator[](unsigned int idx)
	{
		if (idx < 0 || idx > this->_arraySize - 1)
			throw OutOfBounds();
		return this->_array[idx];
	}

	const T& operator[](unsigned int idx) const
	{
		if (idx < 0 || idx > this->_arraySize - 1)
			throw OutOfBounds();
		return this->_array[idx];
	}

	unsigned int size()
	{
		return this->_arraySize;
	}

	class OutOfBounds : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return "Array - Out of range";
			}
	};
};

#endif
