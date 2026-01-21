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
    pm.fordJohnsonSort();
    pm.sortAndMeasureVector();
    pm.sortAndMeasureDeque();
}

