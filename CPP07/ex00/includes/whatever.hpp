/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:47:22 by dsteiger          #+#    #+#             */
/*   Updated: 2025/11/11 18:47:23 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>

class Whatever
{
    public:
        Whatever();
        Whatever(const Whatever &copy);
        Whatever &operator=(const Whatever &src);
        ~Whatever();
};

template <typename T>
void swap(T &s1, T &s2)
{
	T	temp;

	temp = s1;
	s1 = s2;
	s2 = temp;
}

template <typename T>
T min(T &s1, T &s2)
{
	return (s1 < s2 ? s1 : s2);
}

template <typename T>
T max(T &s1, T &s2)
{
	return (s1 > s2 ? s1 : s2);
}

#endif