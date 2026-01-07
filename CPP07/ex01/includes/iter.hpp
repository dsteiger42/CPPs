/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:47:15 by dsteiger          #+#    #+#             */
/*   Updated: 2026/01/07 15:49:13 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

class Iter
{
    public:
        Iter();
        Iter(const Iter &copy);
        Iter &operator=(const Iter &src);
        ~Iter();
};

template <typename A, typename F>
void iter(A *address, const size_t len, F function)
{
    for(size_t i = 0; i < len; i++)
        function(address[i]);
}

#endif