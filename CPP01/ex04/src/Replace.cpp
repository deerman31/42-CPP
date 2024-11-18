#include "Replace.hpp"

Replace::Replace(char **argv)
	:
	_file_Name(argv[1]),
	_s1(argv[2]),
	_s2(argv[3])
	{}

bool	Replace::replace_Process(void) {
	std::string	Original;
	std::string	re_Str;

	if (!get_File(Original))
		return (false);
	if (Original.length() == 0) {
		std::cout << "Contents of the file were empty!" << std::endl;
		return (true);
	}
	re_Str = str_Convert(Original);
	if (!output_File(re_Str)) {
		return (false);
	}
	return (true);
}
