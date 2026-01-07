/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:47:08 by dsteiger          #+#    #+#             */
/*   Updated: 2026/01/07 15:48:25 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T> Array<T>::Array() : _array(NULL), _size(0)
{
	std::cout << "Default constructor called" << std::endl;
}

template <typename T> Array<T>::Array(unsigned int n) : _array(new T[n]),
	_size(n)
{
}

template <typename T> Array<T>::Array(const Array &copy)
{
	_size = copy._size;
	_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = copy._array[i];
}
// A=B, A will become a copy of B, so it needs to delete his old memory
template <typename T> Array<T> &Array<T>::operator=(const Array &src)
{
	if (this != &src)
	{
		delete[] _array;
		_size = src._size;
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = src._array[i];
	}
	return (*this);
}

template <typename T> Array<T>::~Array()
{
    std::cout << "Destructor called" << std::endl;
	delete[] _array;
}

template <typename T> T &Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw Array::IndexOutOfBounds();
    return _array[index];
}

template <typename T> unsigned int Array<T>::size() const
{
    return _size;
}