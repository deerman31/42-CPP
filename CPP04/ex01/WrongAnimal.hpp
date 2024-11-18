#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal {
	protected:
		std::string	_type;
	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		virtual ~WrongAnimal(void);
		WrongAnimal(const WrongAnimal &src);
		WrongAnimal	&operator=(const WrongAnimal &obj);

		void		makeSound(void) const;
		const std::string	getType(void) const;
};

#endif
