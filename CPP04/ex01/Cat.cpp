#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat"), _brain(new Brain()) {
	std::cout << "Cat Default Constructor" << std::endl;
}

Cat::~Cat(void) {
	std::cout << "Cat Destructor" << std::endl;
	if (this->_brain != NULL)
		delete this->_brain;
}

Cat::Cat(const Cat &src) : Animal(src) {
	std::cout << "Cat Cpy Constructor" << std::endl;
	if (src._brain != NULL)
		this->_brain = new Brain(*src._brain);
	else
		this->_brain = NULL;
}

Cat	&Cat::operator=(const Cat &obj) {
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

void	Cat::makeSound(void) const {
	std::cout << "miaou!" << std::endl;
}

const std::string	Cat::getType(void) const {
	return (this->_type);
}

void	Cat::set_Ideas(std::string idea, int i) {
	this->_brain->set_Ideas(idea, i);
}

const std::string	Cat::getIdeas(int i) const {
	return (this->_brain->get_Ideas(i));
}