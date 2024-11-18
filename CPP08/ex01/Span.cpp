#include "Span.hpp"

Span::Span(unsigned int n) : _N(n), _it(0) {}

Span::Span(const Span &src) {
	*this = src;
}

Span	&Span::operator=(const Span &obj) {
	if (this == &obj)
		return *this;
	this->_N = obj._N;
	this->_it = obj._it;
	return *this;
}

Span::~Span(void) {}

void	Span::addNumber(int n) {
	if (this->_N > this->_it.size()) {
		this->_it.push_back(n);
	} else {
		throw std::length_error("The list is full!");
	}
}

unsigned int	Span::shortestSpan(void) {
	if (this->_it.size() <= 1) {
		throw std::invalid_argument("Span cannot be measured because the number of elements is less than 2.");
	}
	std::vector<int>	cpy = this->_it;

	std::sort(cpy.begin(), cpy.end());

	unsigned int	diff = UINT_MAX;

	for (size_t i = 0; i < cpy.size() - 1; i += 1) {
		if (diff > (unsigned int)(cpy[i + 1] - cpy[i]))
			diff = cpy[i + 1] - cpy[i];
	}
	return (diff);
}

unsigned int	Span::longestSpan(void) {
	if (this->_it.size() <= 1) {
		throw std::invalid_argument("Span cannot be measured because the number of elements is less than 2.");
	}
	std::vector<int>::iterator max = std::max_element(this->_it.begin(), this->_it.end());
	std::vector<int>::iterator min = std::min_element(this->_it.begin(), this->_it.end());

	return *max - *min;
}

void	Span::print(void) {
	for (std::vector<int>::const_iterator tmp = this->_it.begin(); tmp != this->_it.end(); tmp += 1) {
		std::cout << *tmp << std::endl;
	}
}
