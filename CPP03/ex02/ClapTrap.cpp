#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	:	_name("NoName"),
		_hit_p(10),
		_energy_p(10),
		_attack_damage(0) {
	std::cout << "Default ClapTrap Constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	:	_name(name),
		_hit_p(10),
		_energy_p(10),
		_attack_damage(0) {
	std::cout << "ClapTrap Constructor " << "[ " << name << " ]" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor " << "[ " << this->_name << " ]" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
	:	_name(src._name),
		_hit_p(src._hit_p),
		_energy_p(src._energy_p),
		_attack_damage(src._attack_damage) {
	std::cout << "ClapTrap Cpy Constructor " << "[ " << src._name << " ]" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &obj) {
	std::cout << "ClapTrap Copy assignment operator called " << "[ " << this->_name << " ] -> [ " << obj._name << " ]" << std::endl;
	if (this == &obj)
		return (*this);
	this->_name = obj._name;
	this->_hit_p = obj._hit_p;
	this->_energy_p = obj._energy_p;
	this->_attack_damage = obj._attack_damage;
	return (*this);
}

void	ClapTrap::attack(const std::string &target) {
	if (this->_energy_p != 0) {
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
		this->_energy_p -= 1;
	} else {
		std::cout << this->_name << " Not enough points!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (amount == 0) {
		std::cout << this->_name << "'s No damage!" << std::endl;
	} else if (_hit_p <= amount) {
		std::cout << this->_name << "'s hit points became 0!" << std::endl;
		_hit_p = 0;
	} else {
		std::cout << this->_name << " took " << amount << " points of damege!" << std::endl;
		this->_hit_p -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energy_p == 0) {
		std::cout << this->_name << " Not enough Energy_Points!" << std::endl;
		return ;
	}
	if (amount == 0) {
		std::cout << "Recovery amount is 0!" << std::endl;
	} else if (this->_hit_p >= UINT_MAX - amount) {
		std::cout << this->_name << " berepaired " << UINT_MAX - this->_hit_p << " points!" << std::endl;
		this->_hit_p = UINT_MAX;
	} else {
		std::cout << this->_name << " berepaired " << amount << " points!" << std::endl;
		this->_hit_p += amount;
	}
	_energy_p -= 1;
}

void	ClapTrap::print_status(void) {
	std::cout << "Name	: " << this->_name << std::endl;
	std::cout << "HP	: " << this->_hit_p << std::endl;
	std::cout << "EP	: " << this->_energy_p << std::endl;
	std::cout << "AD	: " << this->_attack_damage  << std::endl;
}

void	ClapTrap::Atack_Damage(ClapTrap &player) {
	if (this->_energy_p >= 1) {
		attack(player._name);
		player.takeDamage(_attack_damage);
	}
	else
		attack(player._name);
}
