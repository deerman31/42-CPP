#include "Replace.hpp"

static bool	ft_compare(std::string str, std::string::size_type i, std::string s1) {
	for (std::string::size_type index = 0; s1[index]; index += 1) {
		if (s1[index] != str[i + index])
			return (false);
	}
	return (true);
}

std::string	Replace::str_Convert(const std::string Original) {
	std::string						str;
	std::string::size_type			i;

	i = 0;
	while (Original[i]) {
		if (ft_compare(Original, i, _s1)) {
			str += _s2;
			i += _s1.length();
		}
		else {
			str += Original[i];
			i += 1;
		}
	}
	return (str);
}