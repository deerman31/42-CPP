#include "Zombie.hpp"

Zombie::Zombie(void) : _name("no_name") {}

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie(void) {
	std::cout << this->_name << " was discarded!" << std::endl;
}

void	Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name) {
	this->_name = name;
}