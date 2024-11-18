#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <map>
# include <sstream>
# include <cctype>  
# include <cfloat>
# include <cstdlib>
# include <climits>


# define DV "date | value"

# define DBPATH "data.csv"

class DB {
	private:
		std::map<int, float>	_money_odr;
		const std::string		_input;
	public:
		DB(std::map<int, float>, const std::string);
		~DB();
		DB(const DB &);
		DB	&operator=(const DB &);

		float	put_odr(const int &);
		void	rate_calc();
		void	date_search(const std::string &);
		float	date_search2(int);
};

std::map<int, float>	db_set(const std::string &);
size_t					return_len(const std::string &, char);
bool					csv_check(const std::string &);

#endif