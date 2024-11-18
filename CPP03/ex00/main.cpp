#include "ClapTrap.hpp"

int main(void) {
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "< TEST1 >" << std::endl;
	std::cout << "	  [ CODE ]" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "ClapTrap	Default;" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "		↓" << std::endl;
	{
		ClapTrap	Default;
	}
	std::cout << "\n-----------------------------------------" << std::endl;
	std::cout << "< TEST2 >" << std::endl;
	std::cout << "	  [ CODE ]" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "ClapTrap	Human(\"Human\");" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "		↓" << std::endl;
	{
		ClapTrap	Human("Human");
	}
	std::cout << "\n-----------------------------------------" << std::endl;
	std::cout << "< TEST3" << std::endl;
	std::cout << "	  [ CODE ]" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "ClapTrap	Human(\"Human\");" << std::endl;
	std::cout << "ClapTrap	Cpy(Human);" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "		↓" << std::endl;
	{
		ClapTrap	Human("Human");
		ClapTrap	Cpy(Human);
	}
	std::cout << "\n-----------------------------------------" << std::endl;
	std::cout << "< TEST4" << std::endl;
	std::cout << "	  [ CODE ]" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "ClapTrap	Human(\"Human\");\nClapTrap	Assignment;\nAssignment = Human;" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "		↓" << std::endl;
	{
		ClapTrap	Human("Human");
		ClapTrap	Assignment;
		Assignment = Human;
	}
	std::cout << "\n-----------------------------------------" << std::endl;
	std::cout << "< TEST5" << std::endl;
	std::cout << "	  [ CODE ]" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "ClapTrap	Warrior(\"Warrior\")" << std::endl;
	std::cout << "ClapTrap	Monster(\"Monster\")\n" << std::endl;
	std::cout << "Warrior.AtackDamage(Monster);" << std::endl;
	std::cout << "Warrior.print_status();" << std::endl;
	std::cout << "Monster.print_status();" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "		↓" << std::endl;
	{
		ClapTrap	Warrior("Warrior");
		ClapTrap	Monster("Monster");

		Warrior.Atack_Damage(Monster);
		Warrior.print_status();
		Monster.print_status();
	}
	std::cout << "\n-----------------------------------------" << std::endl;
	std::cout << "< TEST6" << std::endl;
	std::cout << "	  [ CODE ]" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "Wizard.print_status()" << std::endl;
	std::cout << "Wizard.beRepaired(100)" << std::endl;
	std::cout << "Wizard.print_status()" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "		↓" << std::endl;
	{
		ClapTrap	Wizard("Wizard");

		Wizard.print_status();
		Wizard.beRepaired(100);
		Wizard.print_status();
	}
	std::cout << "\n-----------------------------------------" << std::endl;
	return (0);
}
