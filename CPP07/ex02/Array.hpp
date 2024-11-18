#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array {
	private:
		T				*_array;
		unsigned int	_size;
	public:
		Array(void) : _array(new T()), _size(0) {}

		Array(long long n) {
			if (UINT_MAX < n || 0 > n)
				throw Array::ConstOverException();
			this->_array = new T[n];
			this->_size = n;
		}

		Array(const Array &src) : _array(new T[src._size]), _size(src._size) {
			for (unsigned int i = 0; i < _size; i += 1) {
				this->_array[i] = src._array[i];
			}
		}

		Array	&operator=(const Array &obj) {
			if (this == &obj)
				return *this;
			if (this->_array != NULL)
				delete[] this->_array;
			this->_array = new T[obj._size];
			this->_size = obj._size;
			for (unsigned int i = 0; i < obj._size; i += 1) {
				this->_array[i] = obj._array[i];
			}
			return *this;
		}

		~Array(void) {
			if (this->_array != NULL) {
				delete[] this->_array;
			}
		}

		T	&operator[](unsigned int index) {
			if (index >= this->_size)
				throw Array::IndexOverException();
			return this->_array[index];
		}

		const T	&operator[](unsigned int index) const {
			if (index >= this->_size)
				throw Array::IndexOverException();
			return this->_array[index];
		}

		unsigned int	size(void) const {
			return this->_size;
		}

		class IndexOverException : public std::exception {
			virtual const char*	what() const throw() {
				return "Index Over!";
			}
		};

		class ConstOverException : public std::exception {
			virtual const char*	what() const throw() {
				return "value out of range!";
			}
		};
};

#endif
