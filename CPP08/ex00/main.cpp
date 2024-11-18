#include "easyfind.hpp"
#include <vector>
#include <iostream>

int	main(void) {
	std::vector<int> myVector;

	for (int i = 1; i <= 10; i += 1) {
		myVector.push_back(i * 10);
	}
	int	i = 0;
	for (std::vector<int>::const_iterator it = myVector.begin(); it != myVector.end(); it += 1) {
		std::cout << i << ": " << *it << std::endl;
		i += 1;
	}

	try {
		std::vector<int>::iterator it = easyfind(myVector, 25);
		std::cout << "Value found! The value is: " << *it << std::endl;
	} catch (std::exception &err) {
		std::cout << err.what() << std::endl;
	}

	try {
		std::vector<int>::const_iterator it = easyfind(myVector, 25);
		std::cout << "Value found! The value is: " << *it << std::endl;
	} catch (std::exception &err) {
		std::cout << err.what() << std::endl;
	}

	std::vector<int> constVector(myVector);
	try {
		std::vector<int>::const_iterator it = easyfind(constVector, 25);
		std::cout << "Value found! The value is: " << *it << std::endl;
	} catch (std::exception &err) {
		std::cout << err.what() << std::endl;
	}
	return 0;
}
