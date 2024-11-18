#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>
# include <iostream>

template <typename T>
void	print(T &c) {
	std::cout << c << std::endl;
}

template <typename T>
void	iter(T *array, size_t size, void (*func)(T &)) {
	for (size_t i = 0; i < size; i += 1) {
		func(array[i]);
	}
}

template <typename T>
void	iter(const T *array, size_t size, void (*func)(const T &)) {
	for (size_t i = 0; i < size; i += 1) {
		func(array[i]);
	}
}

#endif
