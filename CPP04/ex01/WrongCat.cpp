#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("Cat") {
	std::cout << "WrongCat Default Constructor" << std::endl;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat Destructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) {
	std::cout << "WrongCat Cpy Constructor" << std::endl;
}

WrongCat    &WrongCat::operator=(const WrongCat &obj) {
    if (this == &obj)
        return (*this);
    this->_type = obj._type;
    return (*this);
}

void    WrongCat::makeSound(void) const {
	std::cout << "miaou!" << std::endl;
}

const std::string   WrongCat::getType(void) const {
    return (this->_type);
}
