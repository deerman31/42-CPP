#include "Brain.hpp"

Brain::Brain(void) {
    std::cout << "Brain Default Constructor" << std::endl;
    for (int i = 0; i < NUM_IDEAS; i += 1) {
        this->_ideas[i] = "";
    }
}

Brain::~Brain(void) {
    std::cout << "Brain Destructor" << std::endl;
}

Brain::Brain(const Brain &src) {
    std::cout << "Brain Cpy Constructor" << std::endl;
    *this = src;
}

Brain   &Brain::operator=(const Brain &obj) {
	if (this == &obj)
		return (*this);
	for (int i = 0; i < NUM_IDEAS; i += 1) {
		this->_ideas[i] = obj._ideas[i];
	}
	return (*this);
}

void	Brain::set_Ideas(std::string idea, int i) {
	if (i < 0 || NUM_IDEAS < i) {
		std::cout << "index is out of range!" << std::endl;
		return ;
	}
	this->_ideas[i] = idea;
}

const std::string	&Brain::get_Ideas(int i) const {
	if (i < 0 || NUM_IDEAS < i) {
		std::cout << "index is out of range!" << std::endl;
		i = 0;
	}
	return (this->_ideas[i]);
}
