/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:39:00 by dsteiger          #+#    #+#             */
/*   Updated: 2026/01/15 19:02:01 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe() : temp(-1)
{
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	(void)src;
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

bool	isValidInput(std::string str)
{
	size_t	i;

	if (str.empty())
		return (false);
	i = 0;
    if (str == "0")
    {
        std::cerr << "Error: not a positive integer" << std::endl;
        return false;
    }
	while (i < str.size())
	{
		if (!isdigit(static_cast<unsigned char>(str[i])))
		{
			std::cerr << "Error: not a positive integer" << std::endl;
			return (false);
		}
		i++;
	}
	return (true);
}

bool	PmergeMe::isDup(int value)
{
	for (size_t i = 0; i < numbersVec.size(); ++i)
	{
		// compares the new argument with what i already have stored in the vector
		if (numbersVec[i] == value)
			return (true);
	}
	return (false);
}

bool	PmergeMe::parseNumbers(const std::string &str, int &value)
{
	if (!isValidInput(str))
		return (false);
	value = std::atoi(str.c_str());
	if (isDup(value))
	{
		std::cerr << "Error: duplicate number " << value << std::endl;
		return (false);
	}
    numbersVec.push_back(value);
    numbersDeque.push_back(value);
	return (true);
}

void	PmergeMe::formPairs(const std::string &str)
{
	int	value;

	value = std::atoi(str.c_str());
	if (temp == -1)
		temp = value;
	else
	{
		if (temp < value)
		{
			minsVec.push_back(temp);
			maxsVec.push_back(value);

            minsDeque.push_back(temp);
            maxsDeque.push_back(value);
		}
		else
		{
			minsVec.push_back(value);
			maxsVec.push_back(temp);

            minsDeque.push_back(value);
            maxsDeque.push_back(temp);
		}
		temp = -1;
	}
}

void PmergeMe::finalizePairs()
{
    if (temp != -1)
    {
        maxsVec.push_back(temp);
        maxsDeque.push_back(temp);
        temp = -1;
    }
}

void	PmergeMe::printVector(const std::vector<int> &v, const std::string &name) const
{
	std::cout << name << ": ";
	for (size_t i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::printDeque(const std::deque<int> &d, const std::string &name) const
{
    std::cout << name << ": ";
    for (size_t i = 0; i < d.size(); ++i)
        std::cout << d[i] << " ";
    std::cout << std::endl;
}


/*void PmergeMe::printContainers() const
{
    printVector(minsVec, "mins Vec");
    printVector(maxsVec, "maxs Vec");
    std::cout << std::endl;
    printDeque(minsDeque, "mins Deque");
    printDeque(maxsDeque, "maxs Deque");
}*/

void PmergeMe::binaryInsert(std::vector<int> &v, int value)
{
    size_t left = 0;
    size_t right = v.size();

    while (left < right)
    {
        size_t mid = (left + right) / 2;
        if (value < v[mid])
            right = mid;
        else
            left = mid + 1;
    }
    v.insert(v.begin() + left, value);
}

void PmergeMe::fordJohnsonSortVector(std::vector<int> &maxs, std::vector<int> &mins)
{
    if (maxs.size() <= 1)
        return;

    (void)mins;
    std::vector<int> newMins;
    std::vector<int> newMaxs;
    int tmp = -1;

    for (size_t i = 0; i < maxs.size(); ++i)
    {
        if (tmp == -1)
            tmp = maxs[i];
        else
        {
            if (tmp < maxs[i])
            {
                newMins.push_back(tmp);
                newMaxs.push_back(maxs[i]);
            }
            else
            {
                newMins.push_back(maxs[i]);
                newMaxs.push_back(tmp);
            }
            tmp = -1;
        }
    }
    if (tmp != -1)
        newMaxs.push_back(tmp);
    fordJohnsonSortVector(newMaxs, newMins);
    jacobsthalInsert(newMaxs, newMins);
    maxs = newMaxs;
}

void PmergeMe::fordJohnsonSort()
{
    fordJohnsonSortVector(maxsVec, minsVec);
    jacobsthalInsert(maxsVec, minsVec);
}

/*void PmergeMe::printSorted() const
{
    std::cout << "After: ";
    for (size_t i = 0; i < maxsVec.size(); ++i)
        std::cout << maxsVec[i] << " ";
    std::cout << std::endl;
}*/

std::vector<size_t> PmergeMe::jacobsthalSequence(size_t n)
{
    std::vector<size_t> seq;
    seq.push_back(1);
    seq.push_back(1);

    while (seq.back() < n)
    {
        
        size_t size = seq.size();
        seq.push_back(seq[size - 1] + 2 * seq[size - 2]);
    }
    return seq;
}

void PmergeMe::jacobsthalInsert(std::vector<int> &maxs, const std::vector<int> &mins)
{
    std::vector<size_t> jac = jacobsthalSequence(mins.size());
    std::vector<bool> inserted(mins.size(), false);

    for (size_t k = 1; k < jac.size(); ++k)
    {
        size_t start = std::min(jac[k], mins.size());
        size_t end = jac[k - 1];

        for (size_t i = end; i < start; ++i)
        {
            if (!inserted[i])
            {
                binaryInsert(maxs, mins[i]);
                inserted[i] = true;
            }
        }
    }
    for (size_t i = 0; i < mins.size(); ++i)
    {
        if (!inserted[i])
            binaryInsert(maxs, mins[i]);
    }
}

void PmergeMe::sortAndMeasureVector()
{
    std::vector<int> copy = numbersVec; // make a copy for sorting
    std::vector<int> emptyMins;         // real lvalue for mins
    clock_t start = clock();

    // Sort using Ford-Johnson + Jacobsthal
    fordJohnsonSortVector(copy, emptyMins);

    clock_t end = clock();

    // Print After
    std::cout << "\nAfter: ";
    for (size_t i = 0; i < copy.size(); ++i)
        std::cout << copy[i] << " ";
    std::cout << std::endl;

    // Print elapsed time in microseconds
    double elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
    std::cout << std::fixed << std::setprecision(5); // 5 decimal places
    std::cout << "Time to process a range of " << copy.size()
          << " elements with std::vector: " << elapsed << " us" << std::endl;
}

void PmergeMe::sortAndMeasureDeque()
{
    std::deque<int> copy = numbersDeque;
    std::vector<int> tmp(copy.begin(), copy.end()); // convert deque to vector
    std::vector<int> emptyMins;                     // real lvalue for mins
    clock_t start = clock();

    // Sort using Ford-Johnson + Jacobsthal
    fordJohnsonSortVector(tmp, emptyMins);

    // Copy back to deque
    copy.assign(tmp.begin(), tmp.end());

    clock_t end = clock();

    double elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
    std::cout << std::fixed << std::setprecision(5); // 5 decimal places
    std::cout << "Time to process a range of " << copy.size()
          << " elements with std::vector: " << elapsed << " us" << std::endl;
}


void PmergeMe::printBefore() const
{
    std::cout << "Before: ";
    for (size_t i = 0; i < numbersVec.size(); ++i)
        std::cout << numbersVec[i] << " ";
    std::cout << std::endl;
}
