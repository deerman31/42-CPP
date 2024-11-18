#include "BitcoinExchange.hpp"

static std::string	read_file(std::string path) {
	std::ifstream	inputFile(path.c_str());
	if (!inputFile) {
		std::cerr << "Filed: Open file!" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string	line;
	std::string	str;
	while (std::getline(inputFile, line)) {
		str += line + "\n";
	}
	inputFile.close();
	return str;
}

static bool	input_check(const std::string &s) {
	const size_t	len = s.length();
	size_t	i = 0;
	std::string	og;

	while (i < len) {
		og = s.substr(i, return_len(&s[i], '\n'));
		if (og.empty())
			return false;
		if (*og.begin() == ' ' || *og.begin() == '\t')
			return false;
		if (*og.rbegin() == ' ' || *og.rbegin() == '\t')
			return false;
		i += og.length() + 1;
	}
	return true;

}

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return EXIT_FAILURE;
	}
	std::string	input = read_file(argv[1]);
	if (!input_check(input)) {
		std::cerr << "Error: input is inappropriate." << std::endl;
		return EXIT_FAILURE;
	}
	if (!csv_check(DBPATH)) {
		return EXIT_FAILURE;
	}
	DB	db(db_set(read_file(DBPATH)), input);
	db.rate_calc();
	return EXIT_SUCCESS;
}
