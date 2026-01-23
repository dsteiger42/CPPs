/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:28:17 by dsteiger          #+#    #+#             */
/*   Updated: 2026/01/23 16:51:52 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: not enough arguments" << std::endl;
		return (1);
	}
	PmergeMe	pm;
	int			value;
	for (int i = 1; i < argc; ++i)
	{
		if (!pm.parseNumbers(argv[i], value))
			return (1);
		pm.formPairs(argv[i]);
	}
    pm.finalizePairs();
    pm.printBefore();
    pm.sortAndMeasureVector();
    pm.sortAndMeasureDeque();
}

