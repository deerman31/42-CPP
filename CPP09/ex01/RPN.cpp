#include "RPN.hpp"

Calculator::Calculator(const std::string tokens) :
	_tokens(tokens), _stack() {}

Calculator::Calculator(const Calculator &src) :
	_tokens(src._tokens), _stack(src._stack) {}

Calculator::~Calculator() {}

Calculator	&Calculator::operator=(const Calculator &obj) {
	if (this == &obj)
		return *this;
	this->_stack = obj._stack;
	return *this;
}

// Error

static bool	sep_check(const std::string &str) {
	if (*str.begin() == ' ' || *str.rbegin() == ' ')
		return false;

	bool	space_found = false;
	bool	char_found = false;
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
		if (*it == ' ') {
			if (space_found == true)
				return false;
			space_found = true;
			char_found = false;
		} else {
			if (char_found == true)
				return false;
			char_found = true;
			space_found = false;
		}
	}
	return true;
}

static CharType	char_check(char c) {
	if (c == ' ')
		return SPACE;
	else if (std::string("0123456789").find(c) != std::string::npos)
		return NUM;
	else if (std::string("+-*/").find(c) != std::string::npos)
		return OPERATOR;
	return ETC;
}

int	Calculator::calc() {
	long long	tmp;
	long long	n1;
	long long	n2;

	// 文字列が空の場合に例外をthrow
	if (this->_tokens.empty()) {
		throw std::invalid_argument("It's an empty line!");
	// 文字列の先頭が数字以外だと例外をthrow
	} else if (std::string("0123456789").find(*this->_tokens.begin()) == std::string::npos) {
		throw std::invalid_argument("Not in reverse Polish notation!");
	// 数字と演算子がspaceで区切られていなかったら、例外をthrow
	} else if (!sep_check(this->_tokens)) {
		throw std::invalid_argument("Not delimited!");
	}
	for (std::string::const_iterator it = this->_tokens.begin();
		it != this->_tokens.end(); ++it) {
		// 1文字見て、spaceと演算子と数字のどれかを判断し、処理を分岐する
		// それ以外だと例外をthrow
		switch (char_check(*it)) {
			case SPACE:
				break;
			case NUM:
				this->_stack.push(*it - '0');
				break;
			case OPERATOR:
				if (this->_stack.size() < 2) {
					throw std::invalid_argument("Not in reverse Polish notation!");
				}
				n1 = static_cast<long long>(this->_stack.top());
				this->_stack.pop();
				n2 = static_cast<long long>(this->_stack.top());
				this->_stack.pop();
				if (*it == '+') {
					tmp = n2 + n1;
				} else if (*it == '-') {
					tmp = n2 - n1;
				} else if (*it == '*') {
					tmp = n2 * n1;
				} else if (*it == '/') {
					if (n1 == 0) {
						throw std::runtime_error("It will be divided by 0!");
					}
					tmp = n2 / n1;
				}
				if (tmp > static_cast<long long>(INT_MAX) || tmp < static_cast<long long>(INT_MIN)) {
					throw std::runtime_error("Result overflows integer bounds!");
				}
				this->_stack.push(static_cast<int>(tmp));
				break;
			default:
				throw std::invalid_argument("Inappropriate values!");
		}
	}
	if (this->_stack.size() != 1) {
		throw std::invalid_argument("Not in reverse Polish notation!");
	}
	return this->_stack.top();
}
