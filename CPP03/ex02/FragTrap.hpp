#ifndef  FRAGTRAP_HPP
# define  FRAGTRAP_HPP

# include "ClapTrap.hpp"

class  FragTrap : public ClapTrap {
    public:
		// Constructor
        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(const FragTrap &src);
		// Destructor
        ~FragTrap(void);
		// Overload
        FragTrap    &operator=(const FragTrap &obj);

        void    highFivesGuys(void);

		void	attack(const std::string &target);

        //test
		void	Atack_Damage(FragTrap &player);
};

#endif