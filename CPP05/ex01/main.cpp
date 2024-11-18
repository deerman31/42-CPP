#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {
	std::cout << "<TEST1>" << std::endl;
	{
		try {
			Bureaucrat	ykusano("ykusano", 42);
			Form		form("A", 50, 50);
			std::cout << ykusano << std::endl;
			std::cout << form << std::endl;
		} catch (std::exception &err) {
			std::cout << "Error: " << err.what() << std::endl;
		}
	}
	std::cout << "-----------------------------" << std::endl;
	std::cout << "<TEST2>" << std::endl;
	{
		try {
			Bureaucrat	ykusano("ykusano", 42);
			Form		form("A", 50, 50);
			form.beSigned(ykusano);
			std::cout << ykusano << std::endl;
			std::cout << form << std::endl;
		} catch (std::exception &err) {
			std::cout << "Error: " << err.what() << std::endl;
		}
	}
	std::cout << "-----------------------------" << std::endl;
	std::cout << "<TEST3>" << std::endl;
	{
		try {
			Bureaucrat	ykusano("ykusano", 42);
			Form		form("A", 30, 30);
			form.beSigned(ykusano);
			std::cout << ykusano << std::endl;
			std::cout << form << std::endl;
		} catch (std::exception &err) {
			std::cout << "Error: " << err.what() << std::endl;
		}
	}
	std::cout << "-----------------------------" << std::endl;
	std::cout << "<TEST4>" << std::endl;
	{
		try {
			Bureaucrat	ykusano("ykusano", 42);
			Form		form("A", 30, 30);
			ykusano.signForm(form);
			std::cout << ykusano << std::endl;
			std::cout << form << std::endl;
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