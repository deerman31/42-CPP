#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed {
	private:
		int					fixed_num;
		static const int	bits = 8;
	public:
		// constructer
		Fixed(void);
		Fixed(const Fixed &src);
		// destructer
		~Fixed(void);
		// overload
		Fixed	&operator=(const Fixed &obj);
		// ex00
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
