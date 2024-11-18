#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <string>
# include <iostream>
# include <fstream>

class Replace {
	public:
		Replace(char **argv);
		bool	replace_Process(void);
	private:
		std::string	_file_Name;
		std::string	_s1;
		std::string	_s2;
		std::string	str_Convert(const std::string Original);
		bool		get_File(std::string &str);
		bool		output_File(const std::string str);
};

#endif
