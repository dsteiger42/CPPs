#include "../includes/whatever.hpp"

Whatever::Whatever() {}

Whatever::Whatever(const Whatever &copy)
{
    *this = copy;
}

Whatever &Whatever::operator=(const Whatever &src)
{
    (void)src;
	return (*this);
}

Whatever::~Whatever() {}