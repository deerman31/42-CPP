#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed {
	private:
		int					fixed_num;
		static const int	bits = 8;
	public:
		// ex00
		Fixed(void);
		Fixed(const Fixed &src);
		~Fixed(void);
		Fixed	&operator=(const Fixed &obj);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		// ex01
		Fixed(const int num);
		Fixed(const float num);
		float	toFloat(void) const;
		int		toInt(void) const;
		// ex02
		bool	operator>(const Fixed &obj) const;
		bool	operator<(const Fixed &obj) const;
		bool	operator>=(const Fixed &obj) const;
		bool	operator<=(const Fixed &obj) const;
		bool	operator==(const Fixed &obj) const;
		bool	operator!=(const Fixed &obj) const;

		Fixed	operator+(const Fixed &obj) const;
		Fixed	operator-(const Fixed &obj) const;
		Fixed	operator*(const Fixed &obj) const;
		Fixed	operator/(const Fixed &obj) const;

		Fixed	operator++(void);
		Fixed	operator++(int);
		Fixed	operator--(void);
		Fixed	operator--(int);

		static Fixed		&min(Fixed &obj1, Fixed &obj2);
		static const Fixed	&min(const Fixed &obj1, const Fixed &obj2);
		static Fixed		&max(Fixed &obj1, Fixed &obj2);
		static const Fixed	&max(const Fixed &obj1, const Fixed &obj2);
};

std::ostream	&operator<<(std::ostream &os, const Fixed &obj);

#endif

