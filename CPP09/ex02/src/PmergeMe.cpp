/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:39:00 by dsteiger          #+#    #+#             */
/*   Updated: 2026/01/15 15:36:51 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*



*/

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	(void)src;
	return (*this);
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isValidInput(std::string str)
{
    size_t i = 0;
    while(i < str.size()) {
        if(!isdigit(static_cast<unsigned int>(str[i]))) {
            std::cerr << "Error: not a positive integer" << std::endl;
            return false;
        }
        i++;
    }
    return true;
}