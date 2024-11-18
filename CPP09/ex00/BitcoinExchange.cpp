#include "BitcoinExchange.hpp"

static float	ft_stof(const std::string &s) {
	std::istringstream	iss(s);
	float				value;

	iss >> value;
	return value;
}

static int	ft_stoi(const std::string &s) {
	std::istringstream	iss(s);
	int					value;

	iss >> value;
	return value;
}

static bool	is_num(const std::string &date) {
	for (std::string::const_iterator it = date.begin(); it != date.end(); ++it) {
		if (std::isdigit(*it) == 0)
			return false;
	}
	return true;
}

static bool	is_leap_year(int year) {
	if (year % 400 == 0)
		return true;
	if (year % 100 == 0)
		return false;
	if (year % 4 == 0)
		return true;
	return false;
}

static int	date_set(int year, int month) {
	if (month == 2) {
		if (is_leap_year(year)) {
			return 29;
		} else {
			return 28;
		}
	} else if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	return 31;
}

static bool	day_check(const std::string &day, int year, int month) {
	if (!is_num(day))
		return false;
	if (ft_stoi(day) > date_set(year, month) || ft_stoi(day) < 1)
		return false;
	return true;
}

static bool	month_check(const std::string &month) {
	if (!is_num(month))
		return false;
	if (ft_stoi(month) > 12 || ft_stoi(month) < 1)
		return false;
	return true;
}

static bool	year_check(const std::string &year) {
	return is_num(year);
}

static bool	money_order_check(const std::string &money_order) {
	if (std::isdigit(*money_order.begin()) == 0)
		return false;
	double	val = 0;
	int	i = 0;
	for (std::string::const_iterator it = money_order.begin(); it != money_order.end(); ++it) {
		if (*it == '.') {
			if (++i > 1) return false;
		} else if (std::isdigit(*it) == 0) {
			return false;
		}
	}
	std::istringstream iss(money_order);
	if (!(iss >> val) || iss.fail() || !iss.eof()) {
		return false;
	}
	return val <= INT_MAX;
}

static bool	line_check(const std::string &line) {
	for (std::string::const_iterator it = line.begin(); it != line.end(); ++it) {
		if (std::string("0123456789-,.").find(*it) == std::string::npos)
			return false;
	}
	if (line.length() < 12)
		return false;
	if (!year_check(line.substr(0, 4)))
		return false;
	if (!month_check(line.substr(5, 2)))
		return false;
	if (!day_check(line.substr(8, 2), ft_stoi(line.substr(0, 4)), ft_stoi(line.substr(5, 2))))
		return false;
	if (!money_order_check(line.substr(11, std::string::npos)))
		return false;
	return true;
}

static bool	ascending_order_check(const std::string &now, const std::string &before) {
	if (before.empty())
		return true;
	if (now.substr(0, 11) == before.substr(0, 11)) {
		return false;
	}
	int now_year, now_month, now_day, before_year, before_month, before_day;
	now_year = ft_stoi(now.substr(0, 4));
	before_year = ft_stoi(before.substr(0, 4));
	now_month = ft_stoi(now.substr(5, 2));
	before_month = ft_stoi(before.substr(5, 2));
	now_day = ft_stoi(now.substr(8, 2));
	before_day = ft_stoi(before.substr(8, 2));

	return (now_year > before_year || (now_year == before_year && now_month > before_month)
	|| (now_year == before_year && now_month == before_month && now_day > before_day));

}

bool	csv_check(const std::string& filename) {
	std::ifstream file(filename.c_str());  // ファイルを開く
	if (!file) {
		std::cerr << "Fail: open file!" << std::endl;
		return false;
	}
	std::string line;
	if (!std::getline(file, line)) {
		std::cerr << "Error: File is empty!" << std::endl;
		file.close();  // ファイルを閉じる
		return false;
	}
	if (line != "date,exchange_rate") {
		std::cerr << "Error: The first line is not \"date,exchange_rate\"!" << std::endl;
		file.close();  // ファイルを閉じる
		return false;
	}

	std::string	before;
	while (std::getline(file, line)) {  // ファイルから1行ずつ読み込む
		if (!line_check(line) || !ascending_order_check(line, before)) {
			before.clear();
			break;
		}
		before = line;
	}
	file.close();  // ファイルを閉じる
	if (before.empty()) {
		std::cerr << "Error: There is a problem with the format of " << filename << "!" << std::endl;
		return false;
	}
	return true;
}


size_t	return_len(const std::string &s, char c) {
	const size_t	len = s.length();
	size_t			i;

	i = 0;
	while (i < len && s[i] != c) {
		i += 1;
	}
	return i;
}

// DB member function
DB::DB(std::map<int, float> money_odr, const std::string input)
: _money_odr(money_odr), _input(input) {}

DB::~DB(void) {}

DB::DB(const DB &src) :
_money_odr(src._money_odr), _input(src._input) {}

DB	&DB::operator=(const DB &obj) {
	if (this == &obj)
		return *this;
	this->_money_odr = obj._money_odr;
	return *this;
}

float	DB::put_odr(const int &date){ return this->_money_odr[date]; }

static int	date_create(const std::string &s) {
	int		n = 0;

	for (int i = 0; s[i]; i += 1) {
		if (s[i] == '-') {
			continue;
		}
		else if (std::isdigit(s[i]) == 0) {
			break ;
		}
		n = (n * 10) + (s[i] - 48);
	}
	return n;
}


std::map<int, float>	db_set(const std::string &str) {
	const size_t					len = str.length();
	std::map<int, float>	db;
	size_t							i = return_len(str, '\n') + 1;
	while (i < len) {
		std::string	og = str.substr(i, return_len(&str[i], '\n'));
		int			key = date_create(og.substr(0, return_len(og, ',')));
		db[key] = ft_stof(og.substr(return_len(og, ',') + 1, return_len(og, '\n')));
		i += return_len(&str[i], '\n') + 1;
	}
	return db;
}

static bool	date_check(const std::string &og) {
	std::string		year;
	std::string		month;
	std::string		day;

	if (og.length() != 10)
		return false;
	year = og.substr(0, return_len(og, '-'));
	if (year.length() != 4 || !year_check(year))
		return false;
	month = og.substr(5, return_len(&og[5], '-'));
	if (month.length() != 2 || !month_check(month)) {
		return false;
	}
	day = og.substr(8, return_len(&og[8], ' '));
	if (day.length() != 2 || !day_check(day, std::atoi(year.c_str()), std::atoi(month.c_str()))) {
		return false;
	}
	return true;
}

static bool	var_check(const std::string &s) {
	if (s.substr(0, 3) != " | ") {
		return false;
	}
	return true;
}

static bool	value_check2(const std::string &s) {
	size_t	index = 0;
	bool	b = false;

	if (s == "-." || s == ".") {
		std::cerr << "Error: Invalid value => " << s << std::endl;
		return false;
	}
	if (s[0] == '-')
		index = 1;
	for (size_t i = index; s[i]; i += 1) {
		if (s[i] == '.') {
			if (b == true) {
				std::cerr << "Error: Invalid value => " << s << std::endl;
				return false;
			}
			b = true;
		}
		else if (std::isdigit(s[i]) == 0) {
			std::cerr << "Error: Invalid value => " << s << std::endl;
			return false;
		}
	}
	if (s[0] == '-') {
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	if (s.length() > 7 || std::atoi(s.c_str()) > 1000) {
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

static bool	value_check(const std::string &s) {
	if (s.length() == 0) {
		std::cerr << "Error: value is missing." << std::endl;
		return false;
	}
	if (!value_check2(s))
		return false;
	return true;
}

// static int	increment(int num) {
// 	int year = num / 10000;
// 	int month = (num % 10000) / 100; 
// 	int day = num % 100;
// 	int	n = 31;

// 	if (month == 4 || month == 6 || month == 9 || month == 11)
// 		n = 30;
// 	else if (month == 2) {
// 		if (year % 4 == 0)
// 			n = 29;
// 		n = 28;
// 	}
// 	if (day == n) {
// 		day = 1;
// 		month += 1;
// 		if (month == 13) {
// 			month = 1;
// 			year += 1;
// 		}
// 	} else
// 		day += 1;
// 	return ((year * 10000) + (month * 100) + (day));
// }

static int	decrement(int num) {
	int year = num / 10000;
	int month = (num % 10000) / 100; 
	int day = num % 100;
	int	n = 31;

	if (month - 1 == 4 || month - 1 == 6 || month - 1 == 9 || month - 1 == 11)
		n = 30;
	else if (month - 1 == 2) {
		if (year % 4 == 0)
			n = 29;
		n = 28;
	}
	if (day == 1) {
		day = n;
		month -= 1;
		if (month == 0) {
			month = 12;
			year -= 1;
		}
	} else
		day -= 1;
	return ((year * 10000) + (month * 100) + (day));
}

float	DB::date_search2(int n) {
	//int	n1 = n;
	//int	n2 = n;
	std::map<int, float>::const_iterator min = this->_money_odr.begin();

	while (min->first != n) {

		// std::map<int, float>::const_iterator it1 = this->_money_odr.find(n1);
		// if (it1 == _money_odr.end()) {
		// 	n1 = increment(n1);
		// } else {
		// 	return it1->second;
		// }
		std::map<int, float>::const_iterator it = this->_money_odr.find(n);
		if (it == _money_odr.end()) {
			n = decrement(n);
		} else {
			return it->second;
		}
	}
	return min->second;
}

void	DB::date_search(const std::string &og) {
	std::string	date = og.substr(0, return_len(og, ' '));
	if (date_check(date) == false) {
		std::cerr << "Error: bad input => " << date << std::endl;
		return ;
	} else if (!var_check(og.substr(date.length(), og.length()))) {
		std::cerr << "Error: \" | \" is missing." << std::endl;
		return ;
	} else if (!value_check(og.substr(13, og.length())))
		return ;
	int		dn = date_create(date);
	std::map<int, float>::const_iterator it = this->_money_odr.find(dn);
	float	f;
	if (it == _money_odr.end())
		f = date_search2(dn);
	else
		f = it->second;
	float value = ft_stof(og.substr(13, og.length()));
	std::cout << date << " => " << value << " = " << value * f << std::endl;
}

void	DB::rate_calc() {
	const size_t	len = this->_input.length();
	std::map<int, float>	map;
	std::string		og = this->_input.substr(0, return_len(this->_input, '\n'));
	size_t	i = og.length() + 1;

	if (og != DV) {
		std::cerr << "Error: The first line of input must be \"date | value\"." << std::endl;
		return ;
	}
	while (i < len) {
		og = this->_input.substr(i, return_len(&this->_input[i], '\n'));
		date_search(og);
		i += og.length() + 1;
	}
}
