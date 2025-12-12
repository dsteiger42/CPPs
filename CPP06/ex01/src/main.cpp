#include "../includes/serialization.hpp"

int	main(void)
{
	Data data;

	data.name = "Duarte";
	std::cout << data.name << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	Data *deserialization = Serializer::deserialize(raw);

	std::cout << "Pointer:     " << &data << std::endl;
	std::cout << "Raw:         " << raw << std::endl;
	std::cout << "Deserialized:" << Serializer::deserialize(raw) << std::endl;
	if (deserialization == &data)
		std::cout << "Good job: pointers match!" << std::endl;
	else
		std::cout << "Error: pointers do not match." << std::endl;
	return (0);
}