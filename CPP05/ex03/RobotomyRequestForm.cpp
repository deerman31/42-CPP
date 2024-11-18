#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	:
	AForm("RobotomyRequest",
	RobotomyRequestForm::sign,
	RobotomyRequestForm::exec),
	_target("") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	:
	AForm("RobotomyRequest",
	RobotomyRequestForm::sign,
	RobotomyRequestForm::exec),
	_target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	:
	AForm("RobotomyRequest",
	RobotomyRequestForm::sign,
	RobotomyRequestForm::exec),
	_target(src._target) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
	if (this == &obj)
		return *this;
	//*this = obj;
	return *this;
}

const char	*RobotomyRequestForm::executeFailure::what(void) const throw() {
	return "Robotomy failed.";
}

const std::string	&RobotomyRequestForm::getTarget(void) const {
	return this->_target;
}

static bool	randomSuccess(void) {
	return (rand() % 2) == 0;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (this->getsigned() == false)
		throw AForm::IsSignedException();
	else if (this->getexecGrade() < executor.getGrade())
		throw AForm::GradeTooLowException();
	std::cout << "Vrrrrrrrrrrrrrrrrrrrrrrr" << std::endl;

	std::srand(static_cast<unsigned>(std::time(0)));
	if (randomSuccess())
		std::cout << "Success." << std::endl;
	else
		throw (RobotomyRequestForm::executeFailure());
}
