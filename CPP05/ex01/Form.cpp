#include "Form.hpp"

Form::Form(void)
	:
	_name("Noname"),
	_signed(false),
	_sign_grade(BOTTOM),
	_execute_grade(BOTTOM)
	{}

Form::Form(const std::string name, int sign_grade, int execute_grade)
	:
	_name(name),
	_signed(false),
	_sign_grade(sign_grade),
	_execute_grade(execute_grade) {
	if (this->_sign_grade < TOP || this->_execute_grade < TOP)
		throw Form::GradeTooHighException();
	else if (this->_sign_grade > BOTTOM || this->_execute_grade > BOTTOM)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &src)
	:
	_name(src._name),
	_signed(src._signed),
	_sign_grade(src._sign_grade),
	_execute_grade(src._execute_grade) {
	if (this->_sign_grade < TOP || this->_execute_grade < TOP)
		throw Form::GradeTooHighException();
	else if (this->_sign_grade > BOTTOM || this->_execute_grade > BOTTOM)
		throw Form::GradeTooLowException();
}

Form::~Form(void) {}

Form	&Form::operator=(const Form &obj) {
	if (this == &obj)
		return *this;
	this->_signed = obj._signed;
	return *this;
}

const std::string	&Form::getName(void) const {
	return this->_name;
}

bool	Form::getsigned(void) const {
	return this->_signed;
}

int	Form::getsignGrade(void) const {
	return this->_sign_grade;
}

int	Form::getexecGrade(void) const {
	return this->_execute_grade;
}

void	Form::beSigned(const Bureaucrat &obj) {
	if (this->_signed)
		return ;
	if (this->_sign_grade < obj.getGrade())
		throw Form::GradeTooLowException();
	this->_signed = true;
}

const char	*Form::GradeTooHighException::what(void) const throw() {
	return "Grade is high.";
}

const char	*Form::GradeTooLowException::what(void) const throw() {
	return "Grade is low.";
}

std::ostream	&operator<<(std::ostream &os, const Form &obj) {
	std::string	sign;
	if (obj.getsigned() == true)
		sign = "true";
	else
		sign = "false";
	os << obj.getName() << ", form signed " << sign << ", form signgrade " << obj.getsignGrade() << ", form execgrade " << obj.getexecGrade() << ".";
	return os;
}