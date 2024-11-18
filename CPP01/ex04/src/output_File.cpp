#include "Replace.hpp"

bool	Replace::output_File(const std::string str) {
	std::ofstream	output_File(_file_Name + ".replace");

	if (!output_File) {
		std::cerr << "Failed: Create file!" << std::endl;
		return (false);
	}
	output_File << str << std::endl;
	output_File.close();
	return (true);
}