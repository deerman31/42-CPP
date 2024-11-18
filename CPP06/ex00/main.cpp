#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Error: There is only one argument!" << std::endl;
		return 0;
	}
	std::string	Str(argv[1]);
	ScalarConverter::convert(Str);
	return 0;
}
