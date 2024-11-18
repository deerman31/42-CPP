#include "Bureaucrat.hpp"

int	main(void) {
	std::cout << "<TEST1>" << std::endl;
	{
		try {
			Bureaucrat	ykusano("ykusano", 42);
			std::cout << ykusano << std::endl;
		} catch (std::exception &err) {
			std::cout << "Error: " << err.what() << std::endl;
		}
	}
	std::cout << "-----------------------------" << std::endl;
	std::cout << "<TEST2>" << std::endl;
	{
		try {
			Bureaucrat	ykusano("ykusano", 42);
			std::cout << ykusano << std::endl;
			ykusano.upGrade();
			std::cout << ykusano << std::endl;
		} catch (std::exception &err) {
			std::cout << "Error: " << err.what() << std::endl;
		}
	}
	std::cout << "-----------------------------" << std::endl;
	std::cout << "<TEST3>" << std::endl;
	{
		try {
			Bureaucrat	ykusano("ykusano", 42);
			std::cout << ykusano << std::endl;
			ykusano.downGrade();
			std::cout << ykusano << std::endl;
		} catch (std::exception &err) {
			std::cout << "Error: " << err.what() << std::endl;
		}
	}
	std::cout << "-----------------------------" << std::endl;
	std::cout << "<TEST4>" << std::endl;
	{
		try {
			Bureaucrat	ykusano("ykusano", 1);
			std::cout << ykusano << std::endl;
			ykusano.upGrade();
			std::cout << ykusano << std::endl;
		} catch (std::exception &err) {
			std::cout << "Error: " << err.what() << std::endl;
		}
	}
	std::cout << "-----------------------------" << std::endl;
	std::cout << "<TEST5>" << std::endl;
	{
		try {
			Bureaucrat	ykusano("ykusano", 150);
			std::cout << ykusano << std::endl;
			ykusano.downGrade();
			std::cout << ykusano << std::endl;
		} catch (std::exception &err) {
			std::cout << "Error: " << err.what() << std::endl;
		}
	}
	std::cout << "-----------------------------" << std::endl;
	std::cout << "<TEST6>" << std::endl;
	{
		try {
			Bureaucrat	ykusano("ykusano", -100);
			std::cout << ykusano << std::endl;
		} catch (std::exception &err) {
			std::cout << "Error: " << err.what() << std::endl;
		}
	}
	std::cout << "-----------------------------" << std::endl;
	std::cout << "<TEST7" << std::endl;
	{
		try {
			Bureaucrat	ykusano("ykusano", 1000);
			std::cout << ykusano << std::endl;
		} catch (std::exception &err) {
			std::cout << "Error: " << err.what() << std::endl;
		}
	}
	std::cout << "-----------------------------" << std::endl;
	std::cout << "<TEST8" << std::endl;
	{
		try {
			Bureaucrat	ykusano("ykusano", UINT_MAX);
			std::cout << ykusano << std::endl;
		} catch (std::exception &err) {
			std::cout << "Error: " << err.what() << std::endl;
		}
	}
	std::cout << "-----------------------------" << std::endl;
	std::cout << "<TEST9" << std::endl;
	{
		try {
			Bureaucrat	ykusano("ykusano", (INT_MAX + 1));
			std::cout << ykusano << std::endl;
		} catch (std::exception &err) {
			std::cout << "Error: " << err.what() << std::endl;
		}
	}
	std::cout << "-----------------------------" << std::endl;
	return 0;
}
/*
void end(void)__attribute__((destructor));

void end(void)
{
    system("leaks EX");
}
*/