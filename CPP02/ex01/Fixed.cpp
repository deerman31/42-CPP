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
	this->fixed_num = obj.fixed_num;
	return (*this);
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_num);
}

void	Fixed::setRawBits(int const raw) {
	this->fixed_num = raw;
}

/* ex01 */

static int	ft_pow(int n1, int n2) {
	int		num = 1;
	for (int i = 0; i < n2; i += 1) {
		num *= n1;
	}
	return (num);
}

Fixed::Fixed(const int num) : fixed_num(num << bits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num)
	:
	fixed_num(roundf(num * ft_pow(2, this->bits))) {
	std::cout << "Float constructor called" << std::endl;
}

float	Fixed::toFloat(void) const {
	float	f;
	float	r;

	f = ft_pow(2, this->bits);
	r = (float)(this->fixed_num / f);
	return (r);
}

int		Fixed::toInt(void) const {
	return (this->fixed_num >> bits);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &obj) {
	os << obj.toFloat();
	return (os);
}
