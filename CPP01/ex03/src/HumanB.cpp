#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	:
	_name(name),
	_weapon(NULL)
	{}

void	HumanB::attack(void) {
	std::string	type;

	if (this->_weapon != NULL) {
		type = this->_weapon->getType();
	} else {
		type = "bare hands";
	}
	std::cout << this->_name << " attacks with their " << type << "!" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}