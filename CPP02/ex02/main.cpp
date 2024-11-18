#include "Fixed.hpp"

int main( void ) {
	std::cout << "< TEST1 >" << std::endl;
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	std::cout << "< TEST2 >" << std::endl;
	{
		Fixed	a(10);
		Fixed	b(5);
		std::cout << "a = " << a.toFloat() << " b = " << b.toFloat() << std::endl;
		std::cout << "a > b" << std::endl;
		if (a > b)
			std::cout << "OK: a の方が大きい" << std::endl;
		else
			std::cout << "NG: a の方が小さい" << std::endl;
		std::cout << "b < a" << std::endl;
		if (b < a)
			std::cout << "OK: b の方が小さい" << std::endl;
		else
			std::cout << "NG: b の方が大きい" << std::endl;
		std::cout << "a >= b" << std::endl;
		if (a >= b)
			std::cout << "OK: a の方が大きい" << std::endl;
		else
			std::cout << "NG: a の方が小さい" << std::endl;
		std::cout << "b <= a" << std::endl;
		if (b <= a)
			std::cout << "OK: b の方が小さい" << std::endl;
		else
			std::cout << "NG: b の方が大きい" << std::endl;
		std::cout << "a == b" << std::endl;
		if (a == b)
			std::cout << "NG: a と b は等しい" << std::endl;
		else
			std::cout << "OK: a と b は等しくない" << std::endl;
		std::cout << "a != b" << std::endl;
		if (a != b)
			std::cout << "OK: a と b は等しくない" << std::endl;
		else
			std::cout << "NG: a と b は等しい" << std::endl;
	}
	std::cout << "< TEST3" << std::endl;
	{
		Fixed	a(10);
		Fixed	b(5.4f);
		std::cout << "a = " << a.toFloat() << " b = " << b.toFloat() << std::endl;
		std::cout << "a + b" << std::endl;
		std::cout << a + b << std::endl;
		std::cout << "a - b" << std::endl;
		std::cout << a - b << std::endl;
		std::cout << "a * b" << std::endl;
		std::cout << a * b << std::endl;
		std::cout << "a / b" << std::endl;
		std::cout << a / b << std::endl;
	}
	std::cout << "< TEST4 >" << std::endl;
	{
		Fixed	a(10.3f);
		std::cout << "a = " << a.toFloat() << std::endl;
		std::cout << "a++" << std::endl;
		std::cout << a++ << std::endl;
		Fixed	b(10.3f);
		std::cout << "++a" << std::endl;
		std::cout << ++b << std::endl;
		Fixed	c(10.3f);
		std::cout << "a--" << std::endl;
		std::cout << c-- << std::endl;
		Fixed	d(10.3f);
		std::cout << "--a" << std::endl;
		std::cout << --d << std::endl;
	}
	std::cout << "< TEST5 >" << std::endl;
	{
		Fixed	a(10);
		Fixed	b(3);
		const Fixed	c(10);
		const Fixed	d(3);

		std::cout << "a = " << a.toFloat();
		std::cout << " b = " << b.toFloat() << std::endl;
		std::cout << "min" << std::endl;
		std::cout << Fixed::min(a, b) << std::endl;
		std::cout << Fixed::min(c, d) << std::endl;
		//std::cout << "min" << std::endl;
		std::cout << "max" << std::endl;
		std::cout << Fixed::max(a, b) << std::endl;
		std::cout << Fixed::max(c, d) << std::endl;
		//std::cout << "max" << std::endl;
	}
	return 0;
}