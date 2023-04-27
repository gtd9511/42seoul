/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:38:13 by sanghan           #+#    #+#             */
/*   Updated: 2023/04/27 22:36:20 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <typename T>
class Array
{
	private:
		T* _array;
		unsigned int _arraySize;

	public:
		Array() :_array(new T), _arraySize(0){}
		Array(unsigned int n) : _array(new T[n]), _arraySize(n){}
		Array(const Array &obj)
		{
			if (this == obj)
				return ;
			this->_array = NULL;
			this->_arraySize = 0;
			*this = obj;
			//this->_array = new T[obj._arraySize];
			//this->_arraySize = obj._arraySize;
		}

	Array &operator=(const Array &obj)
	{
		if (this != &obj)
		{
			if (this->_array)
				delete this->_array;
			this->_array = new T[obj._arraySize];
			this->_arraySize = obj._arraySize;
			for (unsigned int i = 0; i < this->_arraySize; i++)
				this->arr[i] = obj.arr[i];
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
				return "Out of range! Check index";
			}
	};
};

#endif
