#include "../includes/serialization.hpp"

Serializer::Serializer()
{
	std::cout << "Constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &copy)
{
	*this = copy;
}

Serializer &Serializer::operator=(const Serializer &src)
{
	(void)src;
	return (*this);
}

Serializer::~Serializer()
{
	std::cout << "Destructor called" << std::endl;
}
// reinterpret_cast is only cast that allows convertion between pointer and an integer large enough to hold a pointer (uintptr_t)
uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}