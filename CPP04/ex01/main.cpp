#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp" 
int	main(void)
{
	std::cout << "TEST1" << std::endl;
	std::cout << "-------------------------" << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}

	std::cout << "-------------------------" << std::endl;
	std::cout << "TEST2" << std::endl;
	std::cout << "-------------------------" << std::endl;
	{
		const Animal* test[6];
		for (int i = 0; i < 3; ++i)
			test[i] = new Dog();
		for (int i = 3; i < 6; ++i)
			test[i] = new Cat();
		for (int i = 0; i < 6; ++i)
			delete test[i];
	}

	std::cout << "-------------------------" << std::endl;
	std::cout << "TEST3" << std::endl;
	std::cout << "-------------------------" << std::endl;
	{
		Dog	dog;

		dog.set_Ideas("DOG", 0);
		std::cout << dog.getIdeas(0) << std::endl;
	}

	std::cout << "-------------------------" << std::endl;
	std::cout << "TEST4" << std::endl;
	std::cout << "-------------------------" << std::endl;
	{
		Cat	cat;

		cat.set_Ideas("CAT", 0);
		std::cout << cat.getIdeas(0) << std::endl;
	}
	return (0);
}

/*
void end(void)__attribute__((destructor));

void end(void)
{
    system("leaks EX01");
}
*/
