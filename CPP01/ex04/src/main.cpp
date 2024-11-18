#include "Replace.hpp"

static bool	arg_check(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Incorrect number of arguments!" << std::endl;
		return (false);
	}
	else if (argv[1][0] == '\0') {
		std::cerr << "File name is empty!" << std::endl;
		return (false);	
	}
	else if (argv[2][0] == '\0') {
		std::cerr << "s1 is an empty string!" << std::endl;
		return (false);	
	}
	else if (argv[3][0] == '\0') {
		std::cerr << "s2 is an empty string!" << std::endl;
		return (false);	
	}
	return (true);
}

int main(int argc, char **argv) {
	if (!arg_check(argc, argv))
		return (1);
	Replace	replace(argv);
	if (!replace.replace_Process())
		return (1);
	return (0);
}

/*
void end(void)__attribute__((destructor));

void end(void)
{
	system("leaks EX");
}
*/
