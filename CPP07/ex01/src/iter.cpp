#include "../includes/iter.hpp"

Iter::Iter() {}

Iter::Iter(const Iter &copy)
{
    *this = copy;
}

Iter &Iter::operator=(const Iter &src)
{
    (void)src;
	return (*this);
}

Iter::~Iter() {}