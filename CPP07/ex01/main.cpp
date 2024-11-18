#include "iter.hpp"

class Awesome {
	public:
		Awesome(void) :_n(42) {return;}
		int	get(void) const {return this->_n;}
	private:
		int		_n;
};
std::ostream	&operator<<(std::ostream &o, const Awesome &a) {o << a.get();return o;}
template< typename T >
void	print(T const &x) {std::cout << x << std::endl;return;}

int	main(void)
{
	const int	tab[] = {0, 1, 2, 3, 4};
	const Awesome	tab2[5];

	iter(tab, 5, print);
	iter(tab2, 5, print);
	return 0;
}

/*
int main( void ) {
		int a = 2;
		int b = 3;

		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

		return 0;
}
*/


/*
int main(void) {
	char	array[11] = "abcdefghig";
	//int		array[3] = {1, 2, 3};
	size_t	size = 10;

	iter(array, size, &::print<char>);

	return 0;
}
*/
