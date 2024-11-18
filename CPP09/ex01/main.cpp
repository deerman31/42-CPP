#include "RPN.hpp"
# include <iostream>

int	main(int argc, const char **argv) {
	if (argc != 2) {
		std::cerr << "Error: There is one argument!" << std::endl;
		return EXIT_FAILURE;
	}
	const std::string	tokens(argv[1]);
	Calculator	Calc(tokens);
	try {
		int	num = Calc.calc();
		std::cout << num << std::endl;
	} catch (std::exception &err) {
		std::cerr << "Error: " << err.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
