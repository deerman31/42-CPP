#include "Zombie.hpp"

int	main(void) {
	Zombie	*z_new;
	Zombie	z("Default");

	randomChump("RANDOMCHUMP");
	z_new = newZombie("NEW");
	z_new->announce();
	z.announce();
	delete z_new;
	return 0;
}

// void end(void)__attribute__((destructor));

// void end(void)
// {
// 	system("leaks EX");
// }
