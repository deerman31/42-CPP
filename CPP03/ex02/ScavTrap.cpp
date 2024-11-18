#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
    this->_hit_p = 100;
    this->_energy_p = 50;
    this->_attack_damage = 20;
	std::cout << "Default ScavTrap Constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->_hit_p = 100;
    this->_energy_p = 50;
    this->_attack_damage = 20;
	std::cout << "ScavTrap Constructor " << "[ " << name << " ]" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src) {
	std::cout << "ScavTrap Cpy Constructor " << "[ " << src._name << " ]" << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap Destructor " << "[ " << this->_name << " ]" << std::endl;
}

ScavTrap    &ScavTrap::operator=(const ScavTrap &obj) {
    if (this == &obj)
        return (*this);
    this->_name = obj._name;
    this->_hit_p = obj._hit_p;
    this->_energy_p = obj._energy_p;
    this->_attack_damage = obj._attack_damage;
	std::cout << "ScavTrap Copy assignment operator called " << "[ " << this->_name << " ] -> [ " << obj._name << " ]" << std::endl;
    return (*this);
}

void    ScavTrap::attack(const std::string &target) {
	if (this->_energy_p != 0) {
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
		this->_energy_p -= 1;
	} else {
		std::cout << this->_name << " Not enough points!" << std::endl;
	}
}

void    ScavTrap::guardGate(void) {
    std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode!" << std::endl;
}

void    ScavTrap::Atack_Damage(ScavTrap &player) {
	if (this->_energy_p >= 1) {
		attack(player._name);
		player.takeDamage(_attack_damage);
	}
	else
		attack(player._name);
}