#include "Span.hpp"
#include <iostream>

int	main(void) {
	{
		std::cout << "TEST1" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << "----------------" << std::endl;
	}
	{
		Span	s(10);
		std::cout << "TEST2\n";
		for (int i = 1; i <= 11; i += 1) {
			try {
				s.addNumber(i * 10);
			} catch (std::exception &err) {
				std::cerr << err.what() << std::endl;
			}
		}
		s.print();
		std::cout << "----------------" << std::endl;
	}
	{
		std::cout << "TEST3\n";
		Span	s(10);

		s.addNumber(10);
		s.addNumber(100);
		s.addNumber(30);

		try {
			std::cout << s.longestSpan() << std::endl;
		} catch (std::exception &err) {
			std::cerr << err.what() << std::endl;
		}
		try {
			std::cout << s.shortestSpan() << std::endl;
		} catch (std::exception &err) {
			std::cerr << err.what() << std::endl;
		}
		std::cout << "----------------" << std::endl;
	}
	{
		std::cout << "TEST4\n";
		Span	s(10);

		s.addNumber(10);

		try {
			std::cout << s.longestSpan() << std::endl;
		} catch (std::exception &err) {
			std::cerr << err.what() << std::endl;
		}
		try {
			std::cout << s.shortestSpan() << std::endl;
		} catch (std::exception &err) {
			std::cerr << err.what() << std::endl;
		}
		std::cout << "----------------" << std::endl;
	}
	/*
	{
		std::cout << "TEST5\n";
		std::vector<int>	v;
		for (int i = 1; i <= 10000; i++) {
			v.push_back(i * 11);
		}
		Span	s(10000);
		try {
			s.addNumber(v.begin(), v.end());
		} catch (std::exception &err) {
			std::cerr << err.what() << std::endl;
		}
		s.print();
		std::cout << "----------------" << std::endl;
	}
	*/
	return 0;
}
