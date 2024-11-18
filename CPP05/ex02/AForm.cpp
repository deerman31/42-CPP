#include "AForm.hpp"

AForm::AForm(void)
	:
	_name("Noname"),
	_signed(false),
	_sign_grade(BOTTOM),
	_execute_grade(BOTTOM)
	{}

AForm::AForm(const std::string name, int sign_grade, int execute_grade)
	:
	_name(name),
	_signed(false),
	_sign_grade(sign_grade),
	_execute_grade(execute_grade) {
	if (this->_sign_grade < TOP || this->_execute_grade < TOP)
		throw AForm::GradeTooHighException();
	else if (this->_sign_grade > BOTTOM || this->_execute_grade > BOTTOM)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &src)
	:
	_name(src._name),
	_signed(src._signed),
	_sign_grade(src._sign_grade),
	_execute_grade(src._execute_grade) {
	if (this->_sign_grade < TOP || this->_execute_grade < TOP)
		throw AForm::GradeTooHighException();
	else if (this->_sign_grade > BOTTOM || this->_execute_grade > BOTTOM)
		throw AForm::GradeTooLowException();
}

AForm::~AForm(void) {}

AForm	&AForm::operator=(const AForm &obj) {
	if (this == &obj)
		return *this;
	this->_signed = obj._signed;
	return *this;
}

const std::string	&AForm::getName(void) const {
	return this->_name;
}

bool	AForm::getsigned(void) const {
	return this->_signed;
}

int	AForm::getsignGrade(void) const {
	return this->_sign_grade;
}

int	AForm::getexecGrade(void) const {
	return this->_execute_grade;
}

void	AForm::beSigned(const Bureaucrat &obj) {
	if (this->_signed)
		return ;
	if (this->_sign_grade < obj.getGrade())
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

const char	*AForm::GradeTooHighException::what(void) const throw() {
	return "Grade is high.";
}

const char	*AForm::GradeTooLowException::what(void) const throw() {
	return "Grade is low.";
}

const char 	*AForm::IsSignedException::what(void) const throw() {
	return "Not signed.";
}

std::ostream	&operator<<(std::ostream &os, const AForm &obj) {
	std::string	sign;
	if (obj.getsigned() == true)
		sign = "true";
	else
		sign = "false";
	os << obj.getName() << ", form signed " << sign << ", form signgrade " << obj.getsignGrade() << ", form execgrade " << obj.getexecGrade() << ".";
	return os;
}