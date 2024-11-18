#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base    *generate(void) {
    std::srand(static_cast<unsigned int>(std::time(0)));

    int randomValue = std::rand() % 3;

    if (randomValue == 0)
		return new A;
    else if (randomValue == 1)
        return new B;
	else
        return new C;
    return NULL;
}

void    identify(Base *p) {
	A	*a;
	B	*b;
	C	*c;

	a = dynamic_cast<A *>(p);
	if (a) {
		std::cout << "A" << std::endl;
		return ;
	} 
	b = dynamic_cast<B *>(p);
	if (b) {
		std::cout << "B" << std::endl;
		return ;
	} 
	c = dynamic_cast<C *>(p);
	if (c) {
		std::cout << "C" << std::endl;
		return ;
	} 
	std::cout << "unidentifiable type!" << std::endl;
}

void    identify(Base &p) {
	try {
		A	&a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	} catch (const std::exception &err) {
		try {
			B	&b = dynamic_cast<B &>(p);
			(void)b;
			std::cout << "B" << std::endl;
		} catch (const std::exception &err) {
			try {
				C	&c = dynamic_cast<C &>(p);
				(void)c;
				std::cout << "C" << std::endl;
			} catch (const std::exception &err) {
				std::cout << "unidentifiable type!" << std::endl;
			}
		}
	}
}