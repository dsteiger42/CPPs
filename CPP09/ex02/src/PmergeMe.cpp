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

PmergeMe::PmergeMe()
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

void formPairs(std::string str)
{
    std::vector<int> mins, maxs;
	for (size_t i = 0; i + 1 < str.size(); i += 2)
	{
		if (str[i] < str[i + 1])
		{
			mins.push_back(str[i]);
			maxs.push_back(str[i + 1]);
		}
		else
		{
			mins.push_back(str[i + 1]);
			maxs.push_back(str[i]);
		}
	}
	if (str.size() % 2 != 0)
		maxs.push_back(str.back());
}

/* bool	parseNumber(const std::string &str, int &out)
{
	char	*end;
	long	n;

	if (!isValidInput(str))
		return (false);
	n = std::strtol(str.c_str(), &end, 10);
	if (*end != '\0' || errno == ERANGE || n <= 0 || n > INT_MAX)
		return (false);
	out = static_cast<int>(n);
	return (true);
}

std::vector<size_t> getJacobsthalOrder(size_t n)
{
	size_t	next;
	bool	exists;

	std::vector<size_t> order;
	if (n == 0)
		return (order);
	std::vector<size_t> J;
	J.push_back(0);
	J.push_back(1);
	while (true)
	{
		next = J[J.size() - 1] + 2 * J[J.size() - 2];
		if (next >= n)
			break ;
		J.push_back(next);
	}
	for (size_t i = 0; i < J.size(); ++i)
		order.push_back(J[i]);
	for (size_t i = 0; i < n; ++i)
	{
		exists = false;
		for (size_t j = 0; j < order.size(); ++j)
		{
			if (order[j] == i)
			{
				exists = true;
				break ;
			}
		}
		if (!exists)
			order.push_back(i);
	}
	return (order);
}

void	binaryInsert(std::vector<int> &sorted, int value)
{
	if (sorted.empty())
	{
		sorted.push_back(value);
		return ;
	}
	std::vector<int>::iterator iter = std::lower_bound(sorted.begin(),
			sorted.end(), value);
	sorted.insert(iter, value);
}

std::vector<int> johnsonSortRecursive(const std::vector<int> &c)
{
	if (c.size() <= 1)
		return (c);

	std::vector<int> mins;
	std::vector<int> maxs;
	for (size_t i = 0; i + 1 < c.size(); i += 2)
	{
		if (c[i] < c[i + 1])
		{
			mins.push_back(c[i]);
			maxs.push_back(c[i + 1]);
		}
		else
		{
			mins.push_back(c[i + 1]);
			maxs.push_back(c[i]);
		}
	}
	if (c.size() % 2 != 0)
		maxs.push_back(c.back());

	std::vector<int> sortedMax = johnsonSortRecursive(maxs);
	std::vector<size_t> order = getJacobsthalOrder(mins.size());
	for (size_t i = 0; i < order.size(); ++i)
	{
		size_t idx = order[i];
		if (idx >= mins.size())
			continue ;
		int value = mins[idx];
		binaryInsert(sortedMax, value);
	}
	return (sortedMax);
} */