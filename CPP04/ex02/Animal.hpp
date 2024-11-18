#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal {
	protected:
		std::string	_type;
	public:
		Animal(void);
		Animal(std::string type);
		virtual ~Animal(void);
		Animal(const Animal &src);
		Animal	&operator=(const Animal &src);

		virtual void		makeSound(void) const = 0;
		const std::string	getType(void) const;
};

#endif
