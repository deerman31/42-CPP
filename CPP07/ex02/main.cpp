#include "Array.hpp"

int	main(void) {
	std::cout << "TEST1" << std::endl;
	{
		try {
			const Array<int> a(10);
			std::cout << a.size() << std::endl; 
			// for (unsigned int i = 0; i < a.size(); i += 1) {
			// 	a[i] = i;
			// }
			for (unsigned int i = 0; i <= a.size(); i += 1) {
				std::cout << a[i] << std::endl;
			}
		} catch (std::exception &err) {
			std::cerr << err.what() << std::endl;
		}
	}
	std::cout << "----------------" << std::endl;
	std::cout << "TEST2" << std::endl;
	{
		try {
			Array<int> a(10);
			std::cout << a.size() << std::endl; 
			for (unsigned int i = 0; i <= a.size(); i += 1) {
				a[i] = i;
			}
			for (unsigned int i = 0; i < a.size(); i += 1) {
				std::cout << a[i] << std::endl;
			}
		} catch (std::exception &err) {
			std::cerr << err.what() << std::endl;
		}
	}
	std::cout << "----------------" << std::endl;
	std::cout << "TEST3" << std::endl;
	{
		try {
			Array<int> a(10);
			std::cout << a.size() << std::endl; 
			for (unsigned int i = 0; i < a.size(); i += 1) {
				a[i] = i;
			}
			for (unsigned int i = 0; i <= a.size(); i += 1) {
				std::cout << a[i] << std::endl;
			}
		} catch (std::exception &err) {
			std::cerr << err.what() << std::endl;
		}
	}
	std::cout << "----------------" << std::endl;
	return 0;
}
/*
void end(void)__attribute__((destructor));

void end(void)
{
	system("leaks EX");
}
*/
