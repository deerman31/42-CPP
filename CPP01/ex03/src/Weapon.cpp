#include "Weapon.hpp"

Weapon::Weapon(void) : _name("some other type of club") {}

Weapon::Weapon(std::string name) : _name(name) {}

const std::string	&Weapon::getType(void) {
	const std::string	&type(this->_name);

	return (type);
}

void	Weapon::setType(std::string name) {
	this->_name = name;
}