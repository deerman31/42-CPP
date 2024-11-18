#include "Harl.hpp"

void	Harl::debug(void) {
	std::cout << "[ DEBUG MESSAGE ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void) {
	std::cout << "[ INFO MESSAGE ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;

}

void	Harl::warning(void) {
	std::cout << "[ WARNING MESSAGE ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl; 
}

void	Harl::error(void) {
	std::cout << "[ ERROR MESSAGE ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

static int	level_Num(std::string str) {
	const std::string	strs[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int					i;

	i = 0;
	while (i < 4) {
		if (str == strs[i])
			break ;
		i += 1;
	}
	return (i);
}

void	Harl::complain(std::string level) {
	const int	num = level_Num(level);
	void (Harl::*functionArray[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	if (num == 4)
		std::cout << "Harl couldn't handle!" << std::endl;
	else
		(this->*functionArray[num])();
}

