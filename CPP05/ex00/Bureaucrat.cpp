#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
	: _name("Noname"), _grade(BOTTOM)
	{}

Bureaucrat::Bureaucrat(const std::string name, int grade)
	: _name(name), _grade(grade) {
	if (this->_grade < TOP)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > BOTTOM)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
	: _name(src._name), _grade(src._grade)
	{}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &obj) {
	if (this == &obj)
		return *this;
	this->_grade = obj.getGrade();
	return *this;
}

const std::string	&Bureaucrat::getName(void) const {
	return this->_name;
}

int	Bureaucrat::getGrade(void) const {
	return this->_grade;
}

void	Bureaucrat::upGrade(void) {
	this->_grade -= 1;
	if (this->_grade < TOP)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::downGrade(void) {
	this->_grade += 1;
	if (this->_grade > BOTTOM)
		throw Bureaucrat::GradeTooLowException();
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw() {
	return "Grade is high.";
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw() {
	return "Grade is low.";
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return os;
}
