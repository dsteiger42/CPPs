/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:28:25 by dsteiger          #+#    #+#             */
/*   Updated: 2026/01/23 18:17:55 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>
#include <limits.h>
#include <ctime>
#include <cstdlib>
#include <iomanip>

class PmergeMe
{
    private:
        std::vector<int> numbersVec;
        std::vector<int> minsVec;
	    std::vector<int> maxsVec;

        std::deque<int> numbersDeque;
        std::deque<int> minsDeque;
        std::deque<int> maxsDeque;

        int temp;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &src);
        ~PmergeMe();

        bool isDup(int value);
        bool parseNumbers(const std::string &str, int &value);
        void formPairs(const std::string &str);
        void finalizePairs();

        template<typename C>
        void binaryInsert(C &v, int value);

        template<typename C>
        void fordJohnsonSortCont(C &maxs, C &mins);
        void fordJohnsonSort();
        std::vector<size_t> jacobsthalSequence(size_t n);

        template<typename C>
        void jacobsthalInsert(C &maxs, C &mins);
        void sortAndMeasureVector();
        void sortAndMeasureDeque();
        void printBefore() const;
};


#endif