/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:23:04 by dsteiger          #+#    #+#             */
/*   Updated: 2025/12/22 17:52:39 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
#define EASYFIND_H

#include <iostream>
#include <algorithm>
#include <vector>

class EasyFind
{
    public:
        EasyFind();
        EasyFind(const EasyFind &copy);
        EasyFind &operator=(const EasyFind &src);
        ~EasyFind();
};

template <typename T>
void easyfind(T &container, int number);

template <typename T>
void other_easyfind(T &container, int number);

#include "easyfind.tpp"

#endif