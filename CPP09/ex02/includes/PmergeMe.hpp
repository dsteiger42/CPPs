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
        void binaryInsert(std::vector<int> &v, int value);
        void fordJohnsonSortVector(std::vector<int> &maxs, std::vector<int> &mins);
        void fordJohnsonSort();
        std::vector<size_t> jacobsthalSequence(size_t n);
        void jacobsthalInsert(std::vector<int> &maxs, const std::vector<int> &mins);
        void sortAndMeasureVector();
        void sortAndMeasureDeque();
        void printBefore() const;
};


#endif