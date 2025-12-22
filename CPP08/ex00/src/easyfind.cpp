#include "../includes/easyfind.hpp"

EasyFind::EasyFind() {}

EasyFind::EasyFind(const EasyFind &copy)
{
    *this = copy;
}

EasyFind &EasyFind::operator=(const EasyFind &src)
{
	(void)src;
	return (*this);
}

EasyFind::~EasyFind() {}