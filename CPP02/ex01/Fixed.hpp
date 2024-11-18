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
		// constructer
		Fixed(void);
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &src);
		// destructer
		~Fixed(void);
		// overload
		Fixed	&operator=(const Fixed &obj);
		// ex00
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		// ex01
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &os, const Fixed &obj);

#endif

