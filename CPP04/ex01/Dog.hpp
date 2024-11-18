#ifndef Dog_HPP
# define Dog_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain	*_brain;
	public:
		Dog(void);
		virtual ~Dog(void);
		Dog(const Dog &src);
		Dog	&operator=(const Dog &src);

		virtual void		makeSound(void) const;
		const std::string	getType(void) const;

		void	set_Ideas(std::string idea, int i);
		const std::string	getIdeas(int i) const;
};

#endif
