#include "Contact.hpp"

static bool	Isnum(std::string s) {
	for (size_t i = 0; s[i]; i += 1) {
		if (!isdigit(s[i]))
			return (false);
	}
	return (true);
}

static std::string	Info_Set(std::string info) {
	std::string	s;
	int		r;

	r = 1;
	while (r == 1) {
		std::cout << info << ":	";
		getline(std::cin, s);
		if (s.length() == 0)
			std::cout << "Empty letters are inappropriate!" << std::endl;
		else if (info == PHONE_NUM && !Isnum(s))
			std::cout << "Phone Numbers are numbers only!!!" << std::endl;
		else
			r = 0;
	}
	return (s);
}

void	Contact::Add_Sub(Contact &contact) {
	std::string	s;
	contact.first_name = Info_Set(FIRST_NAME);
	contact.last_name = Info_Set(LAST_NAME);
	contact.nickname = Info_Set(NICKNAME);
	contact.phone_num = Info_Set(PHONE_NUM);
	contact.secret = Info_Set(SECRET);
	std::cout << std::endl;
}

void	Contact::Put(Contact contact) {
	std::cout << FIRST_NAME << ":	" << contact.first_name << std::endl;
	std::cout << LAST_NAME << ":	" << contact.last_name << std::endl;
	std::cout << NICKNAME << ":	" << contact.nickname << std::endl;
	std::cout << PHONE_NUM << ":	" << contact.phone_num << std::endl;
	std::cout << SECRET << ":	" << contact.secret << std::endl;
	std::cout << "-----------------------------------" << std::endl;
}

void	Contact::OverWrite(Contact contats[8]) {
	for (size_t i = 0; i < 7; i += 1) {
		contats[i].first_name = contats[i + 1].first_name;
		contats[i].last_name = contats[i + 1].last_name;
		contats[i].nickname = contats[i + 1].nickname;
		contats[i].phone_num = contats[i + 1].phone_num;
		contats[i].secret = contats[i + 1].secret;
	}
}

void	Contact::S_Put(Contact contats[8], size_t size) {
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     Index" << "|first name" << "| last name" << "|  nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	if (size == 0) {
		std::cout << "|    Can't Find Any Contact Information!    |" << std::endl;
	}
	for (size_t i = 0; i < size; i += 1) {
		std::cout << "|" << std::setw(10) << std::right << i + 1 << "|";
		if (contats[i].first_name.length() <= 10)
			std::cout << std::setw(10) << std::right << contats[i].first_name << "|";
		else
			std::cout << contats[i].first_name.substr(0, 9) << "." << "|";
		if (contats[i].last_name.length() <= 10)
			std::cout << std::setw(10) << std::right << contats[i].last_name << "|";
		else
			std::cout << contats[i].last_name.substr(0, 9) << "." << "|";
		if (contats[i].nickname.length() <= 10)
			std::cout << std::setw(10) << std::right << contats[i].nickname << "|" << std::endl;
		else
			std::cout << contats[i].nickname.substr(0, 9) << "." << "|" << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl << std::endl;
}