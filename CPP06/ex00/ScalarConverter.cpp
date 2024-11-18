#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const std::string &literal) {
	(void)literal;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
	(void)src;
}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &obj) {
	if (this == &obj)
		return (*this);
	return (*this);
}


static bool	IsChar(const std::string &str) {
	if (str.length() == 1) {
		if (isprint(str[0]) == 1 && isdigit(str[0]) == 0)
			return true;
	}
	return false;
}

static bool	IsInt(const std::string &str) {
	const size_t	len = str.length();
	size_t	i;

	i = 0;
	if (str[0] == '-' && len != 1)
		i = 1;
	while (i < len) {
		if (isdigit(str[i]) == 0)
			return false;
		i += 1;
	}
	return true;
}

static bool	IsFloat(const std::string &str) {
	const size_t	len = str.length() - 1;
	bool			b = false;
	size_t			index = 0;

	if (str.find('.') == std::string::npos)
		return false;
	if (str[len] != 'f')
		return false;
	if (str[0] == '-')
		index = 1;
	for (size_t i = index; i < len; i += 1) {
		if (str[i] == '.' && b == true)
			return false;
		else if (str[i] == '.') {
			b = true;
			i += 1;
		}
		if (isdigit(str[i]) == 0)
			return false;
	}
	return true;
}

static bool	IsDouble(const std::string &str) {
	const size_t	len = str.length();
	bool			b = false;
	size_t			index = 0;

	if (str.find('.') == std::string::npos)
		return false;
	if (str[0] == '-')
		index = 1;
	for (size_t i = index; i < len; i += 1) {
		if (str[i] == '.' && b == true)
			return false;
		else if (str[i] == '.') {
			b = true;
			i += 1;
		}
		if (isdigit(str[i]) == 0)
			return false;
	}
	return true;
}

static int	PossibleTypes(const std::string &str) {
	if (str == "-inf" || str == "+inf" || str == "nan")
		return DPseudo_literal;
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return FPseudo_literal;
	if (IsChar(str))
		return Char;
	if (IsInt(str))
		return Int;
	if (IsFloat(str))
		return Float;
	if (IsDouble(str))
		return Double;
	return Impossible;
}

static int	changeInt(const std::string &str) {
	int	n;
	std::stringstream iss(str);

	iss >> n;
	return n;
}

static float	changeFloat(const std::string &str) {
	float	n;
	std::stringstream iss(str.substr(0, str.length() - 1));

	iss >> n;
	return n;
}

static double	changeDouble(const std::string &str) {
	double	n;
	std::stringstream iss(str);

	iss >> n;
	return n;
}

static void	putChar(char c) {
	const int		i = static_cast<int>(c);
	const float		f = static_cast<float>(c);
	const double	d = static_cast<double>(c);

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

static void	putInt(int n) {
	const float		f = static_cast<float>(n);
	const double	d = static_cast<double>(n);

	if (isprint(n))
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

static void	putFloat(float n) {
	const int		i = static_cast<int>(n);
	const double	d = static_cast<double>(n);

	if (isprint(n))
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << n << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

static void	putDouble(double n) {
	const int		i = static_cast<int>(n);
	const double	f = static_cast<float>(n);

	if (isprint(n))
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << n << std::endl;
}

static void	putPseudoLiteralD(const std::string &str) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << str << std::endl;
	std::cout << "double: " << str << "f" << std::endl;
}

static void	putPseudoLiteralF(const std::string &str) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << str.substr(0, str.length() - 1) << std::endl;
	std::cout << "double: " << str << std::endl;
}

void	ScalarConverter::convert(const std::string &str) {
	const int	type_num = PossibleTypes(str);

	if (type_num == Char) {
		putChar(static_cast<char>(str[0]));
	} else if (type_num == Int) {
		putInt(changeInt(str));
	} else if (type_num == Float) {
		putFloat(changeFloat(str));
	} else if (type_num == Double) {
		putDouble(changeDouble(str));
	} else if (type_num == DPseudo_literal) {
		putPseudoLiteralD(str);
	} else if (type_num == FPseudo_literal) {
		putPseudoLiteralF(str);
	} else {
		std::cout << "Type conversion is not possible!" << std::endl;
	}
}