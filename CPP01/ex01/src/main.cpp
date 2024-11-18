#include "Zombie.hpp"

int	main(void) {
	Zombie	*zs;
	int		N;

	N = 10;
	zs = zombieHorde(N, "ykusano");
	for (int i = 0; i < N; i += 1) {
		std::cout << i + 1 << "	";
		zs[i].announce();
	}
	delete[] zs;
	return (0);
}

// void end(void)__attribute__((destructor));

// void end(void)
// {
// 	system("leaks EX");
// }