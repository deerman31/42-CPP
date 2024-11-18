#ifndef Cat_HPP
# define Cat_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain	*_brain;
	public:
		Cat(void);
		virtual ~Cat(void);
		Cat(const Cat &src);
		Cat	&operator=(const Cat &src);

		virtual void		makeSound(void) const;
		const std::string	getType(void) const;

		void	set_Ideas(std::string idea, int i);
		const std::string	getIdeas(int i) const;
};

#endif
