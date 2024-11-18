#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <cctype>

const std::string	FIRST_NAME = "First Name";
const std::string	LAST_NAME = "Last Name";
const std::string	NICKNAME = "Nick Name";
const std::string	PHONE_NUM = "Phone Number";
const std::string	SECRET = "Darkest Secret";

class Contact {
	public:
		void	Add_Sub(Contact &contact);
		void	Put(Contact contact);
		void	OverWrite(Contact contats[8]);
		void	S_Put(Contact contats[8], size_t size);
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_num;
		std::string	secret;
};

#endif