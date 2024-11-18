#include <iostream>
#include <string>
#include <cctype>

static void	big(std::string &s) {
	size_t		i;

	for (i = 0; s[i]; i += 1) {
		if (islower(s[i])) {
			s[i] = std::toupper(s[i]);
		}
	}
}

int	main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	} else {

		for (int i = 1; i < argc; i += 1) {
			std::string s(argv[i]);
			big(s);
			std::cout << s;
		}
	}
	std::cout << std::endl;
	return (0);
}
