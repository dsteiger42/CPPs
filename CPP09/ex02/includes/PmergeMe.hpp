#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
#include <deque>
#include <string>
#include <limits.h>
#include <algorithm>
#include <ctime>
#include <cerrno>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &src);
        ~PmergeMe();

};
bool parseNumber(const std::string &str, int &out);
std::vector<size_t> getJacobsthalOrder(size_t n);
void binaryInsert(std::vector<int> &sorted, int value);
std::vector<int> johnsonSortRecursive(const std::vector<int> &c);
void formPairs(std::string str);

#endif