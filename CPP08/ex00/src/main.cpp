/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:23:15 by dsteiger          #+#    #+#             */
/*   Updated: 2025/12/22 17:58:09 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"

// vector is a dynamic array, as I can access each element and can also add or remove them
/*
Vector is good for this exercise cuz it has "Contiguous memory", making iteration easy, and cuz its dynamic.
List is not as great, cuz Linked list → not contiguous → iteration slower, more memory overhead.
*/
int main()
{
    //std::vector<int> v = {1, 2, 3, 4, 5}; not supported by c++98
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    // found / not found.
    try {
        easyfind(v, 3);
        easyfind(v, 10);
    }
    catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

    std::cout << "--------------------------" << std::endl;

    // not found / doesnt even appear cuz expection has been thrown already
    try {
        easyfind(v, 10234232);
        easyfind(v, 3);
    }
    catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

    std::cout << "--------------------------" << std::endl;

    try {
        other_easyfind(v, 4);
        other_easyfind(v, 42);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "--------------------------" << std::endl;

    try {
        other_easyfind(v, 1);
        other_easyfind(v, 5);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "--------------------------" << std::endl;

    // test empty vector
    std::vector<int> empty;
    try {
        other_easyfind(empty, 1);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}