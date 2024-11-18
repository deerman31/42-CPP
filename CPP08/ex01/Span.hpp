#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <limits>
# include <iostream>

class Span {
	private:
		unsigned int		_N;
		std::vector<int>	_it;
	public:
		Span(unsigned int n);
		Span(const Span &src);
		~Span(void);
		Span	&operator=(const Span &obj);

		void			addNumber(int n);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);

		template <typename T>
		void	addNumber(const T &b, const T &e) {
			if (this->_it.size() + std::distance(b, e) > this->_N)
				throw std::length_error("The list is full!");
			for (T tmp = b; tmp != e; ++tmp) {
				this->addNumber(*tmp);
			}
		}

		void	print(void);
};

#endif
