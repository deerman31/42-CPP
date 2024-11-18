#ifndef RPN_CPP
# define RPN_CPP

# include <string>
# include <stack>
# include <cctype>
# include <cstdlib>
# include <climits>
# include <stdexcept>

enum CharType{
	SPACE,
	NUM,
	OPERATOR,
	ETC,
};

class Calculator {
	private:
		const std::string	_tokens;
		std::stack<int>		_stack;
	public:
		Calculator(const std::string tokens);
		Calculator(const Calculator &src);
		~Calculator();
		Calculator	&operator=(const Calculator &obj);
		int	calc();
};

#endif
