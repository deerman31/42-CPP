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
	: _name(src._name), _grade(src._grade) {
	if (this->_grade < TOP)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > BOTTOM)
		throw Bureaucrat::GradeTooLowException();
}

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

void	Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
	} catch (std::exception &err) {
		std::cout << this->_name << " couldn’t sign " << form.getName() << " because " << err.what() << std::endl;
		return ;
	}
	std::cout << this->_name << " signed " << form.getName() << "." << std::endl;
}