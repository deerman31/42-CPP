#include "Harl.hpp"

int	main(void) {
	Harl	harl;

	std::cout << "< DEBUG >" << std::endl;
	harl.complain("DEBUG");
	std::cout << "< INFO >" << std::endl;
	harl.complain("INFO");
	std::cout << "< WARNING >" << std::endl;
	harl.complain("WARNING");
	std::cout << "< ERROR >" << std::endl;
	harl.complain("ERROR");
	std::cout << "< NO MATCH >" << std::endl;
	harl.complain("42");
	return (0);
}
/*
void end(void)__attribute__((destructor));

void end(void)
{
	system("leaks EX");
}
*/
