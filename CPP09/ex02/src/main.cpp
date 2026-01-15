#include "../includes/PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
	{
		std::cerr << "Error: not enough arguments" << std::endl;
		return (1);
	}
    std::vector<int> vec;
    for (int i = 1; i < argc; ++i)
    {
        formPairs(argv[i]);
    }
}

/* int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: not enough arguments" << std::endl;
		return (1);
	}
	std::vector<int> vec;
	for (int i = 1; i < argc; ++i)
	{
		int n;
		std::string arg(argv[i]);
		if (!parseNumber(arg, n))
		{
			std::cerr << "Error: invalid number '" << arg << "'" << std::endl;
			return (1);
		}
		if (std::find(vec.begin(), vec.end(), n) != vec.end())
		{
			std::cerr << "Error: duplicate number '" << n << "'" << std::endl;
			return (1);
		}

		vec.push_back(n);
	}
	std::cout << "Before: ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	vec = johnsonSortRecursive(vec);
	std::cout << "After: ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
	return (0);
} */