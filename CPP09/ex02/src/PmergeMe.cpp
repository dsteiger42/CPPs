/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:39:00 by dsteiger          #+#    #+#             */
/*   Updated: 2026/01/23 18:17:34 by dsteiger         ###   ########.fr       */
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
		return (false);
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

bool PmergeMe::isDup(int value)
{
	for (size_t i = 0; i < numbersVec.size(); ++i)
	{
		// compares the new argument with what i already have stored in the vector
		if (numbersVec[i] == value)
			return (true);
	}
	return (false);
}

bool PmergeMe::parseNumbers(const std::string &str, int &value)
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

void PmergeMe::formPairs(const std::string &str)
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

template<typename C>
void PmergeMe::binaryInsert(C &v, int value)
{
	size_t	left;
	size_t	right;
	size_t	mid;

	left = 0;
	right = v.size();
	while (left < right)
	{
		mid = (left + right) / 2;
		if (value < v[mid])
			right = mid;
		else
			left = mid + 1;
	}
	v.insert(v.begin() + left, value);
}
template<typename C>
void PmergeMe::fordJohnsonSortCont(C &maxs, C &mins)
{
	int	temp;

	if (maxs.size() <= 1)
		return ;
	(void)mins;
	C newMins;
	C newMaxs;
	temp = -1;
	for (size_t i = 0; i < maxs.size(); ++i)
	{
		if (temp == -1)
			temp = maxs[i];
		else
		{
			if (temp < maxs[i])
			{
				newMins.push_back(temp);
				newMaxs.push_back(maxs[i]);
			}
			else
			{
				newMins.push_back(maxs[i]);
				newMaxs.push_back(temp);
			}
			temp = -1;
		}
	}
	if (temp != -1)
		newMaxs.push_back(temp);
	fordJohnsonSortCont(newMaxs, newMins);
	jacobsthalInsert(newMaxs, newMins);
	maxs = newMaxs;
}

void PmergeMe::fordJohnsonSort()
{
	fordJohnsonSortCont(maxsVec, minsVec);
}

std::vector<size_t> PmergeMe::jacobsthalSequence(size_t n)
{
	size_t	size;

	std::vector<size_t> seq;
	seq.push_back(1);
	seq.push_back(1);
	while (seq.back() < n)
	{
		size = seq.size();
		seq.push_back(seq[size - 1] + 2 * seq[size - 2]);
	}
	return (seq);
}

template<typename C>
void PmergeMe::jacobsthalInsert(C &maxs, C &mins)
{
	size_t	start;
	size_t	end;

	std::vector<size_t> jac = jacobsthalSequence(mins.size());
	std::vector<bool> inserted(mins.size(), false);
	for (size_t k = 1; k < jac.size(); ++k)
	{
		start = std::min(jac[k], mins.size());
		end = jac[k - 1];
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
	clock_t	start;
	clock_t	end;
	double	elapsed;

	std::vector<int> copy = numbersVec;
	std::vector<int> emptyMins;
	start = clock();
	fordJohnsonSortCont(copy, emptyMins);
	end = clock();
	std::cout << "\nAfter: ";
	for (size_t i = 0; i < copy.size(); ++i)
		std::cout << copy[i] << " ";
	std::cout << std::endl;
	elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << copy.size() << " elements with std::vector: " << elapsed << " us" << std::endl;
}

void PmergeMe::sortAndMeasureDeque()
{
	clock_t	start;
	clock_t	end;
	double	elapsed;

	std::deque<int> copy = numbersDeque;
	std::deque<int> emptyMins;
	start = clock();
	fordJohnsonSortCont(copy, emptyMins);
	end = clock();
	elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << copy.size() << " elements with std::deque: " << elapsed << " us" << std::endl;
}

void PmergeMe::printBefore() const
{
	std::cout << "Before: ";
	for (size_t i = 0; i < numbersVec.size(); ++i)
		std::cout << numbersVec[i] << " ";
	std::cout << std::endl;
}
