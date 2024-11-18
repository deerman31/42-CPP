#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat(void);
		virtual ~WrongCat(void);
		WrongCat(const WrongCat &src);
		WrongCat	&operator=(const WrongCat &obj);

		void		makeSound(void) const;
		const std::string	getType(void) const;
};

#endif
