#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"), _brain(new Brain()) {
	std::cout << "Dog Default Constructor" << std::endl;
}

Dog::~Dog(void) {
	std::cout << "Dog Destructor" << std::endl;
	if (this->_brain != NULL)
		delete this->_brain;
}

Dog::Dog(const Dog &src) : Animal(src) {
	std::cout << "Dog Cpy Constructor" << std::endl;
	if (src._brain != NULL)
		this->_brain = new Brain(*src._brain);
	else
		this->_brain = NULL;
}

Dog	&Dog::operator=(const Dog &obj) {
	if (this == &obj)
		return (*this);
	this->_type = obj._type;
	if (this->_brain != NULL)
		delete this->_brain;
	if (obj._brain != NULL)
		this->_brain = new Brain(*obj._brain);
	else
		this->_brain = NULL;
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "ouaf ouaf!" << std::endl;
}

const std::string	Dog::getType(void) const {
	return (this->_type);
}

void	Dog::set_Ideas(std::string idea, int i) {
	this->_brain->set_Ideas(idea, i);
}

const std::string	Dog::getIdeas(int i) const {
	return (this->_brain->get_Ideas(i));
}