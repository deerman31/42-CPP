#include "Base.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>

Base    *generate(void);
void    identify(Base *p);
void    identify(Base &p);

int	main(void) {
	Base	*base;

	try {
		base = generate();
	} catch (const std::exception &err) {
		std::cerr << "Failed: new!" << std::endl;
		return (1);
	}
	std::cout << "ポインター" << std::endl;
	identify(base);
	std::cout << "参照" << std::endl;
	identify(&(*base));
	delete base;
	return 0;
}

// void end(void)__attribute__((destructor));

// void end(void)
// {
// 	system("leaks EX");
// }
