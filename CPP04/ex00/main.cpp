#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void) {
	{
		std::cout << "TEST 1" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete i;
		delete j;
		delete meta;
		}
	std::cout << "\n----------------------" << std::endl;
	std::cout << "TEST 2" << std::endl;
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		meta->makeSound();
		delete i;
		delete meta;
	}
	std::cout << "\n----------------------" << std::endl;
	std::cout << "TEST 3" << std::endl;
	{
		Animal	animal;
		std::cout << animal.getType() << " " << std::endl;
		animal.makeSound();
	}
	std::cout << "\n----------------------" << std::endl;
	std::cout << "TEST 4" << std::endl;
	{
		Cat	cat;
		std::cout << cat.getType() << " " << std::endl;
		cat.makeSound();
	}
	std::cout << "\n----------------------" << std::endl;
	std::cout << "TEST 5" << std::endl;
	{
		Dog	dog;
		std::cout << dog.getType() << " " << std::endl;
		dog.makeSound();
	}
	std::cout << "\n----------------------" << std::endl;
	std::cout << "TEST 6" << std::endl;
	{
		WrongAnimal	wronganimal;
		std::cout << wronganimal.getType() << " " << std::endl;
		wronganimal.makeSound();
	}
	std::cout << "\n----------------------" << std::endl;
	std::cout << "TEST 7" << std::endl;
	{
		WrongCat	wrongcat;
		std::cout << wrongcat.getType() << " " << std::endl;
		wrongcat.makeSound();
	}

	return (0);
}

/*
void end(void)__attribute__((destructor));

void end(void)
{
    system("leaks EX00");
}
*/
