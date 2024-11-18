#include "Replace.hpp"

bool	Replace::get_File(std::string &str) {
	std::ifstream	inputFile(_file_Name);

	if (!inputFile) {
		std::cerr << "Failed: Open file!" << std::endl;
		return (false);
	}

	std::string	line;
	while (std::getline(inputFile, line)) {
		str += line + "\n";
	}

	inputFile.close();
	if (str.length() != 0)
		str.resize(str.length() - 1);
	return (true);
}
