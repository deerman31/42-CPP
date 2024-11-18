#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &Weapon)
	:
	_name(name),
	_weapon(Weapon)
	{}

void	HumanA::attack(void) {
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << "!" << std::endl;
}