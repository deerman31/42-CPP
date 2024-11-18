#include "Animal.hpp"

Animal::Animal(void) : _type("animal") {
	std::cout << "Animal Default Constructor" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "Animal Constructor" << std::endl;
}

Animal::~Animal(void) {
	std::cout << "Animal Destructor"  << std::endl;
}

Animal::Animal(const Animal &src) : _type(src._type) {
	std::cout << "Animal Cpy Constructor" << std::endl;
}


Animal	&Animal::operator=(const Animal &obj) {
	if (this == &obj)
		return (*this);
	this->_type = obj._type;
	return (*this);
}

const std::string	Animal::getType(void) const {
	return (this->_type);
}
