#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("Wrong Animal") {
	std::cout << "WrongAnimal Default Constructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "WrongAnimal Constructor" << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal Destructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) : _type(src._type) {
	std::cout << "WrongAnimal Cpy Constructor" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj) {
    if (this == &obj)
        return (*this);
    this->_type = obj._type;
    return (*this);
}

void    WrongAnimal::makeSound(void) const {
	std::cout << "Wrong Animal!" << std::endl;
}

const std::string   WrongAnimal::getType(void) const {
    return (this->_type);
}
