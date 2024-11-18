#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
	std::cout << "Dog Default Constructor" << std::endl;
}

Dog::~Dog(void) {
	std::cout << "Dog Destructor" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src) {
	std::cout << "Dog Cpy Constructor" << std::endl;
}

Dog	&Dog::operator=(const Dog &obj) {
	if (this == &obj)
		return (*this);
	this->_type = obj._type;
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "ouaf ouaf!" << std::endl;
}

const std::string	Dog::getType(void) const {
	return (this->_type);
}
