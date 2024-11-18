#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <sstream>
# include <algorithm>
# include <stdexcept>
# include <iterator>

template <typename T>
typename T::const_iterator	easyfind(const T &c, int n) {
	typename T::const_iterator it = std::find(c.begin(), c.end(), n);
	if (it == c.end()) {
		std::stringstream ss;
		ss << "Value " << n << " not found in the container!";
		throw std::out_of_range(ss.str());
	}
	return it;
}

template <typename T>
typename T::iterator	easyfind(T &c, int n) {
	typename T::iterator it = std::find(c.begin(), c.end(), n);
	if (it == c.end()) {
		std::stringstream ss;
		ss << "Value " << n << " not found in the container!";
		throw std::out_of_range(ss.str());
	}
	return it;
}

#endif
