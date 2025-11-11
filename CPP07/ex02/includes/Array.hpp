/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:47:11 by dsteiger          #+#    #+#             */
/*   Updated: 2025/11/11 19:21:02 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

# define RED "\033[31m"
#define RESET   "\033[0m"

template <typename T> class Array
{
  private:
	T *_array;
	unsigned int _size;

  public:
	Array();
	Array(unsigned int n);
	Array(const Array &copy);
	Array &operator=(const Array &src);
	~Array();
	T &operator[](unsigned int index);
	unsigned int size() const;
	class IndexOutOfBounds : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return (RED "Index is out of bounds." RESET);
		}
	};
};

#include "Array.tpp"
#endif