#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <cctype>
# include <climits>

enum type {
	Char,
	Int,
	Float,
	Double,
	DPseudo_literal,
	FPseudo_literal,
	Impossible,
};

class ScalarConverter{
	private:
		ScalarConverter(void);
		ScalarConverter(const std::string &literal);
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter(void);
		ScalarConverter	&operator=(const ScalarConverter &obj);
	public:
		static void	convert(const std::string &literal);
};

#endif
