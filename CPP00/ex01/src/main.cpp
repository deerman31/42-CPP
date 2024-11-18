#include "PhoneBook.hpp"

int	main(void) {
	PhoneBook	book;
	std::string	s;
	int			r;

	r = 1;
	while (r == 1)
	{
		std::cout << "Command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, s);
		r = book.Reception(s);
	}
	return (0);
}