#include "FragTrap.hpp"

int main(void) {
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "< TEST1 >" << std::endl;
	std::cout << "	  [ CODE ]" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "FragTrap	Default;" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "		↓" << std::endl;
	{
		FragTrap	Default;
	}
	std::cout << "\n-----------------------------------------" << std::endl;
	std::cout << "< TEST2 >" << std::endl;
	std::cout << "	  [ CODE ]" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "FragTrap	Human(\"Human\");" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "		↓" << std::endl;
	{
		FragTrap	Human("Human");
	}
	std::cout << "\n-----------------------------------------" << std::endl;
	std::cout << "< TEST3" << std::endl;
	std::cout << "	  [ CODE ]" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "FragTrap	Human(\"Human\");" << std::endl;
	std::cout << "FragTrap	Cpy(Human);" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "		↓" << std::endl;
	{
		FragTrap	Human("Human");
		FragTrap	Cpy(Human);
	}
	std::cout << "\n-----------------------------------------" << std::endl;
	std::cout << "< TEST4" << std::endl;
	std::cout << "	  [ CODE ]" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "FragTrap	Human(\"Human\");\nFragTrap	Assignment;\nAssignment = Human;" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "		↓" << std::endl;
	{
		FragTrap	Human("Human");
		FragTrap	Assignment;
		Assignment = Human;
	}
	std::cout << "\n-----------------------------------------" << std::endl;
	std::cout << "< TEST5" << std::endl;
	std::cout << "	  [ CODE ]" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "FragTrap	Warrior(\"Warrior\")" << std::endl;
	std::cout << "FragTrap	Monster(\"Monster\")\n" << std::endl;
	std::cout << "Warrior.AtackDamage(Monster);" << std::endl;
	std::cout << "Warrior.print_status();" << std::endl;
	std::cout << "Monster.print_status();" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "		↓" << std::endl;
	{
		FragTrap	Warrior("Warrior");
		FragTrap	Monster("Monster");

		Warrior.Atack_Damage(Monster);
		Warrior.print_status();
		Monster.print_status();
	}
	std::cout << "\n-----------------------------------------" << std::endl;
	std::cout << "< TEST6" << std::endl;
	std::cout << "	  [ CODE ]" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "FragTrap	Human(\"Human\");\n" << std::endl;
	std::cout << "Human.highFivesGuys();" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "		↓" << std::endl;
	{
		FragTrap	Human("Human");

		Human.highFivesGuys();
	}
	std::cout << "\n-----------------------------------------" << std::endl;
	return (0);
}
