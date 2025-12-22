/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:47:19 by dsteiger          #+#    #+#             */
/*   Updated: 2025/12/22 16:23:44 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"

template <typename I>
void print_arr(I &array)
{
    std::cout << "Array: " << array << std::endl;
}

int main(void)
{
    int integer[] = {1, 2, 3, 4, 5};
    std::string array[] = {"RUN", "boy"};
    float floating[] = {1.2f, 6.4f, 23.1f};
    iter(integer, sizeof(integer) / sizeof(integer[0]), print_arr<int>);
    iter(array, sizeof(array) / sizeof(array[0]), print_arr<std::string>);
    iter(floating, sizeof(floating) / sizeof(floating[0]), print_arr<float>);
}