#include "Serializer.hpp"
#include <iostream>

int main(void) {
    Data    	data;
	Data		*tmp;

	data.num = 42;
	std::cout << "Original" << std::endl;
	std::cout << &data << std::endl;
	std::cout << data.num << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "Cast" << std::endl;
	uintptr_t	n = Serializer::serialize(&data);
	tmp = Serializer::deserialize(n);
	std::cout << tmp << std::endl;
	std::cout << tmp->num << std::endl;
}
