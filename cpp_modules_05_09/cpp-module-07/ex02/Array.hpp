/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 04:50:18 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/15 07:03:49 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template<typename T>
class	Array
{
	private:
		T*				_array;
		unsigned int	_size;

	public:
		class	InvalidIndex : public std::exception
		{
			public:
				virtual char const * what(void) const throw() {
					return "InvalidIndex : index is out of bounds";
				}
		};

		Array<T> () : _array(NULL), _size(0)
		{}

		Array<T> (unsigned int n) : _array(new T[n]), _size(n)
		{
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = T();
		}

		Array<T> (const Array<T> &other) : _array(NULL)
		{
			*this = other;
		}

   		~Array<T> ()
		{
			delete[] _array;
		}

		Array<T> & operator=(const Array<T> &other)
		{
			 if (this == &other)
        		return *this;

			if (_array)
				delete[] _array;
			_array = NULL;

			_size = other._size;
			if (_size == 0)
				return *this;

			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = other._array[i];

			return *this;
		}

		T& operator[](unsigned int index)
		{
			if (index >= _size)
				throw InvalidIndex();
			return _array[index];
		}

		const T& operator[](unsigned int index) const
		{
			if (index >= _size)
				throw InvalidIndex();
			return _array[index];
		}

		unsigned int	size(void) const
		{
			return _size;
		}
};

#endif /* ARRAY_HPP */
