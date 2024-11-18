#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
    :
    AForm("PresidentialPardon",
    PresidentialPardonForm::sign,
    PresidentialPardonForm::exec),
    _target("") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
    :
    AForm("PresidentialPardon",
    PresidentialPardonForm::sign,
    PresidentialPardonForm::exec),
    _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
    :
    AForm("PresidentialPardon",
    PresidentialPardonForm::sign,
    PresidentialPardonForm::exec),
    _target(src._target) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm  &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj) {
    if (this == &obj)
        return *this;
    return *this;
}

const std::string   &PresidentialPardonForm::getTarget(void) const {
    return this->_target;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (this->getsigned() == false)
		throw AForm::IsSignedException();
	else if (this->getexecGrade() < executor.getGrade())
		throw AForm::GradeTooLowException();
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
