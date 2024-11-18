#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook(void);
		int		Reception(std::string cmd);
	private:
		void	Add(void);
		void	Search(void);
		Contact	contacts[8];
		size_t	size;
};

#endif