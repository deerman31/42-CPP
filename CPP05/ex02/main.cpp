#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void) {
	AForm	*S;
	std::cout << "<TEST1>" << std::endl;
	{
		try {
			Bureaucrat	ykusano("ykusano", 1);
			try {
				S = new ShrubberyCreationForm("home");
				//S = new RobotomyRequestForm("home");
				//S = new PresidentialPardonForm("home");
				try {
					S->beSigned(ykusano);
					ykusano.executeForm(*S);
				} catch (std::exception &err) {
					std::cout << "Error2: " << err.what() << std::endl;
				}
				delete S;
			} catch (const std::bad_alloc &err) {
				std::cerr << "Failed: " << err.what() << std::endl; 
			}
		} catch (std::exception &err) {
			std::cout << "Error1: " << err.what() << std::endl;
		}
	}
	std::cout << "-----------------------------" << std::endl << std::endl;
	return 0;
}
/*
void end(void)__attribute__((destructor));

void end(void)
{
    system("leaks EX");
}
*/