#ifndef Cat_HPP
# define Cat_HPP

#include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat(void);
		virtual ~Cat(void);
		Cat(const Cat &src);
		Cat	&operator=(const Cat &src);

		virtual void	makeSound(void) const;
		const std::string	getType(void) const;
};

#endif
