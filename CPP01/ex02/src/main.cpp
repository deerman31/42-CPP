#include <iostream>
#include <string>

int	main(void) {
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "< MEMORY ADDRESS >" << std::endl;
	std::cout << "string		= " << &string << std::endl;
	std::cout << "stringPTR	= " << stringPTR << std::endl;
	std::cout << "stringREF	= " << &stringREF << std::endl;
	std::cout << "\n< VALUE >" << std::endl;
	std::cout << "string		= " << string << std::endl;
	std::cout << "stringPTR	= " << *stringPTR << std::endl;
	std::cout << "stringREF	= " << stringREF << std::endl;
	return (0);
}

// void end(void)__attribute__((destructor));

// void end(void)
// {
// 	system("leaks EX");
// }