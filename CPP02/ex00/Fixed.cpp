#include "Fixed.hpp"

Fixed::Fixed(void) : fixed_num(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}


Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &obj) {
		return (*this);
	}
	this->setRawBits(obj.getRawBits());
	return (*this);
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_num);
}

void	Fixed::setRawBits(int const raw) {
	this->fixed_num = raw;
}
