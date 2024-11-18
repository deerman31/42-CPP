#ifndef SCAVTRAP_CPP
# define SCAVTRAP_CPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
		// Constructor
        ScavTrap(void);
        ScavTrap(std::string name);
		ScavTrap(const ScavTrap &src);
		// Destructor
        ~ScavTrap(void);
		// Overload
        ScavTrap    &operator=(const ScavTrap &obj);

		void	attack(const std::string &target);

        void    guardGate(void);

        //test
        void    Atack_Damage(ScavTrap &player);
};

#endif