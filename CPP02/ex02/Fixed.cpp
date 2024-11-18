#include "Fixed.hpp"

Fixed::Fixed(void) : fixed_num(0) {
}

Fixed::Fixed(const Fixed &src) {
	*this = src;
}

Fixed::~Fixed(void) {
}

Fixed	&Fixed::operator=(const Fixed &obj) {
	if (this == &obj) {
		return (*this);
	}
	this->fixed_num = obj.fixed_num;
	return (*this);
}

int	Fixed::getRawBits(void) const {
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
}

Fixed::Fixed(const float num)
	:
	fixed_num(roundf(num * ft_pow(2, this->bits))) {
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

/* ex02 */

bool	Fixed::operator>(const Fixed &obj) const {
	if (this->getRawBits() > obj.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed &obj) const {
	if (this->getRawBits() < obj.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &obj) const {
	if (this->getRawBits() >= obj.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &obj) const {
	if (this->getRawBits() <= obj.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed &obj) const {
	if (this->getRawBits() == obj.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &obj) const {
	if (this->getRawBits() != obj.getRawBits())
		return (true);
	return (false);
}

Fixed	Fixed::operator+(const Fixed &obj) const {
	Fixed	R;

	R.setRawBits(this->getRawBits() + obj.getRawBits());
	return (R);
}

Fixed	Fixed::operator-(const Fixed &obj) const {
	Fixed	R;

	R.setRawBits(this->getRawBits() - obj.getRawBits());
	return (R);
}

Fixed	Fixed::operator*(const Fixed &obj) const {
	Fixed	R;

	R.setRawBits((this->getRawBits() * obj.getRawBits()) >> Fixed::bits);
	return (R);
}

Fixed	Fixed::operator/(const Fixed &obj) const {
	Fixed	R;

	R.setRawBits((this->getRawBits() << Fixed::bits) / obj.getRawBits());
	return (R);
}

Fixed	Fixed::operator++(void) {
	this->fixed_num++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	cpy(*this);
	this->fixed_num++;
	return (cpy);
}

Fixed	Fixed::operator--(void) {
	this->fixed_num--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	cpy(*this);
	this->fixed_num--;
	return (cpy);
}

Fixed	&Fixed::min(Fixed &obj1, Fixed &obj2) {
	if (obj1 < obj2) {
		return (obj1);
	}
	return (obj2);
}

const Fixed	&Fixed::min(const Fixed &obj1, const Fixed &obj2) {
	if (obj1 < obj2) {
		return (obj1);
	}
	return (obj2);
}

Fixed	&Fixed::max(Fixed &obj1, Fixed &obj2) {
	if (obj1 > obj2) {
		return (obj1);
	}
	return (obj2);
}

const Fixed	&Fixed::max(const Fixed &obj1, const Fixed &obj2) {
	if (obj1 > obj2) {
		return (obj1);
	}
	return (obj2);
}
