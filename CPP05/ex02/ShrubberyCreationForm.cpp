#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	:
	AForm("ShrubberyCreation", sign, exec), _target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	:
	AForm("ShrubberyCreation", sign, exec), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	:
	AForm("ShrubberyCreation", sign, exec), _target(src._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj) {
	if (this == &obj)
		return *this;
	return *this;
}

const char	*ShrubberyCreationForm::executeFailure::what(void) const throw() {
	return "Failed to open file.";
}

const std::string	&ShrubberyCreationForm::getTarget(void) const {
	return this->_target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (this->getsigned() == false)
		throw AForm::IsSignedException();
	else if (this->getexecGrade() < executor.getGrade())
		throw AForm::GradeTooLowException();
	std::ofstream	output_File(this->_target + "_shrubbery");
	if (!output_File) {
		throw (ShrubberyCreationForm::executeFailure());
		return ;
	}
	std::string	Ascii_Trees = "       ^\n      ^^^\n     ^^^^^\n    ^^^^^^^\n   ^^^^^^^^^\n  ^^^^^^^^^^^\n ^^^^^^^^^^^^^\n^^^^^^^^^^^^^^^\n       |\n       |";
	output_File << Ascii_Trees << std::endl;
	output_File.close();
}