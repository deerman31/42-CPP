#include "FragTrap.hpp"
/*
• Name, which is passed as parameter to a constructor
• Hit points (100), represent the health of the ClapTrap
• Energy points (100)
• Attack damage (30)
*/

FragTrap::FragTrap(void) : ClapTrap() {
    this->_hit_p = 100;
    this->_energy_p = 100;
    this->_attack_damage = 30;
	std::cout << "Default FragTrap Constructor" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->_hit_p = 100;
    this->_energy_p = 100;
    this->_attack_damage = 30;
	std::cout << "FragTrap Constructor " << "[ " << name << " ]" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src) {
	std::cout << "FragTrap Cpy Constructor " << "[ " << src._name << " ]" << std::endl;
}

FragTrap    &FragTrap::operator=(const FragTrap &obj) {
	std::cout << "FragTrap Copy assignment operator called " << "[ " << this->_name << " ] -> [ " << obj._name << " ]" << std::endl;
    if (this == &obj)
        return (*this);
    this->_name = obj._name;
    this->_hit_p = obj._hit_p;
    this->_energy_p = obj._energy_p;
    this->_attack_damage = obj._attack_damage;
    return (*this);
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap Destructor " << "[ " << this->_name << " ]" << std::endl;
}

void    FragTrap::attack(const std::string &target) {
	if (this->_energy_p != 0) {
		std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
		this->_energy_p -= 1;
	} else {
		std::cout << this->_name << " Not enough points!" << std::endl;
	}
}

void    FragTrap::highFivesGuys(void) {
    std::cout << "Wonderful!" << std::endl;
}


void	FragTrap::Atack_Damage(FragTrap &player) {
	if (this->_energy_p >= 1) {
		attack(player._name);
		player.takeDamage(_attack_damage);
	}
	else
		attack(player._name);
}
