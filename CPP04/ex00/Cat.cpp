#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
	std::cout << "Cat Default Constructor" << std::endl;
}

Cat::~Cat(void) {
	std::cout << "Cat Destructor" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src) {
	std::cout << "Cat Cpy Constructor" << std::endl;
}

Cat	&Cat::operator=(const Cat &obj) {
	if (this == &obj)
		return (*this);
	this->_type = obj._type;
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "miaou!" << std::endl;
}

const std::string	Cat::getType(void) const {
	return (this->_type);
}
