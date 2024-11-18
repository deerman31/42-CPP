#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	size = 0;
}

void	PhoneBook::Add(void) {
	if (size == 8){
		size -= 1;
		contacts[size].OverWrite(contacts);
	}
	contacts[size].Add_Sub(contacts[size]);
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "Contact information has been added." << std::endl;
	contacts[size].Put(contacts[size]);
	size += 1;
}

static bool	Isnum(std::string s) {
	int		num;

	num = 0;
	for (size_t i = 0; s[i]; i += 1) {
		if (!isdigit(s[i]))
			return (false);
		num = (num * 10) + s[i] - '0'; 
		if (num >= 9)
			return (false);
	}
	if (num == 0)
		return (false);
	return (true);
}

void	PhoneBook::Search(void) {
	size_t		num;
	std::string	s;

	contacts[size].S_Put(contacts, size);
	while (size != 0) {
		std::cout << "Enter Index: ";
		std::getline(std::cin, s);
		if (s.length() == 0 || !Isnum(s)) {
			std::cout << "Please enter a number 1 ~ 8!" << std::endl;
			continue ;
		}
		num = (size_t)stoi(s);
		if (1 <= num && num <= size) {
			std::cout << "-----------------------------------" << std::endl;
			std::cout << "Index		" << num << std::endl;
			contacts[num - 1].Put(contacts[num - 1]);
			break ;
		} else {
			std::cout << num << " is not found" << std::endl;
			continue ;
		}
	}
}

int	PhoneBook::Reception(std::string cmd) {
	if (cmd == "ADD") {
		Add();
	} else if (cmd == "SEARCH") {
		std::cout << std::endl;
		Search();
	} else if (cmd == "EXIT") {
		std::cout << "Exit the Program!" << std::endl;
		return (0);
	}
	else
		std::cout << "Error: The appropriate command is ADD, SEARCH, EXIT!!!" << std::endl;
	return (1);
}
