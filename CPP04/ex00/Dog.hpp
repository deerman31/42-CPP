#ifndef Dog_HPP
# define Dog_HPP

#include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog(void);
		virtual ~Dog(void);
		Dog(const Dog &src);
		Dog	&operator=(const Dog &src);

		virtual void	makeSound(void) const;
		const std::string	getType(void) const;
};

#endif
