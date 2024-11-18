#include "Intern.hpp"

Intern::Intern(void) {
}

Intern::Intern(const Intern &src) {
	*this = src;
}

Intern::~Intern(void) {
}

Intern  &Intern::operator=(const Intern &obj) {
    if (this == &obj)
        return *this;
	return *this;
}

static int	num_set(const std::string form_name) {
	const std::string	strs[3] = {"ShrubberyCreation",
									"RobotomyRequest",
									"PresidentialPardon"};
	int					i = 0;
	while (i < 3) {
		if (strs[i] == form_name)
			break ;
		i += 1;
	}
	return i;
}

static AForm	*Shrubberymake(const std::string target) {
	AForm	*form;

	form = new ShrubberyCreationForm(target);
	return form;
}

static AForm	*Robotomymake(const std::string target) {
	AForm	*form;

	form = new RobotomyRequestForm(target);
	return form;
}

static AForm	*Presidentmake(const std::string target) {
	AForm	*form;

	form = new PresidentialPardonForm(target);
	return form;
}

AForm	*Intern::makeForm(const std::string form_name, const std::string target) {
	const int	num = num_set(form_name);

	AForm	*(*functionArray[3])(const std::string target) = {&Shrubberymake, &Robotomymake, &Presidentmake};
	if (num == 3) {
		std::cerr << "The form name is incorrect." << std::endl;
		return NULL;
	}
	std::cout << "Intern creates " << form_name << std::endl;
	return functionArray[num](target);
}