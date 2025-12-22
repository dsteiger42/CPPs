#include "easyfind.hpp"

template <typename T>
void easyfind(T &container, int number)
{
    typename T::iterator iter = std::find(container.begin(), container.end(), number);
    if(iter != container.end())
        std::cout << "Found match: " << *iter << std::endl;
    else
        throw std::runtime_error("Value not found");
}


// lower_bound need to be sorted first and returns the 1st element that matches
template <typename T>
void other_easyfind(T &container, int number)
{
    std::sort(container.begin(), container.end());

    typename T::iterator iter = std::lower_bound(container.begin(), container.end(), number);
    if(iter != container.end() && *iter == number)
        std::cout << "Found match: " << *iter << std::endl;
    else
        throw std::runtime_error("Value not found");
}