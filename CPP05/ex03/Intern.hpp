#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <string>

class	AForm;

class Intern {
	public:
		Intern(void);
		Intern(const Intern &src);
		~Intern(void);
		Intern	&operator=(const Intern &obj);
		AForm	*makeForm(const std::string form_name, const std::string target);
};

#endif
