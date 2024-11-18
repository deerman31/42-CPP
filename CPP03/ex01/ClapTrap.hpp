#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {
	protected:
		std::string		_name;
		unsigned int	_hit_p;
		unsigned int	_energy_p;
		unsigned int	_attack_damage;
	public:
		// Constructor
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &src);
		// Destructor
		~ClapTrap();
		// Overload
		ClapTrap	&operator=(const ClapTrap &obj);
		//
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		// test
		void	print_status(void);
		void	Atack_Damage(ClapTrap &player);
};

#endif
