#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <iostream>
#include <stack>
#include <sstream>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &src);
        ~PmergeMe();

        bool isValidInput(std::string str);
};

#endif