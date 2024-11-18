#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp" 
int	main(void)
{
	/*
	std::cout << "TEST1" << std::endl;
	std::cout << "-------------------------" << std::endl;
	{
		Animal	a;
	}
	std::cout << "-------------------------" << std::endl;
	*/
	std::cout << "TEST2" << std::endl;
	std::cout << "-------------------------" << std::endl;
	{
		const Animal* j = new Cat();
		j->makeSound();
		delete j;//should not create a leak
	}
	std::cout << "-------------------------" << std::endl;
	std::cout << "TEST3" << std::endl;
	std::cout << "-------------------------" << std::endl;
	{
		const Animal* j = new Dog();
		j->makeSound();
		delete j;//should not create a leak
	}
	std::cout << "-------------------------" << std::endl;
	return (0);
}

/*
void end(void)__attribute__((destructor));

void end(void)
{
    system("leaks EX02");
}
*/
