#include "ScavTrap.hpp"

int main(void) {
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "< TEST1 >" << std::endl;
	std::cout << "	  [ CODE ]" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "ScavTrap	Default;" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "		↓" << std::endl;
	{
		ScavTrap	Default;
	}
	std::cout << "\n-----------------------------------------" << std::endl;
	std::cout << "< TEST2 >" << std::endl;
	std::cout << "	  [ CODE ]" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "ScavTrap	Human(\"Human\");" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "		↓" << std::endl;
	{
		ScavTrap	Human("Human");
	}
	std::cout << "\n-----------------------------------------" << std::endl;
	std::cout << "< TEST3" << std::endl;
	std::cout << "	  [ CODE ]" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "ScavTrap	Human(\"Human\");" << std::endl;
	std::cout << "ScavTrap	Cpy(Human);" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "		↓" << std::endl;
	{
		ScavTrap	Human("Human");
		ScavTrap	Cpy(Human);
	}
	std::cout << "\n-----------------------------------------" << std::endl;
	std::cout << "< TEST4" << std::endl;
	std::cout << "	  [ CODE ]" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "ScavTrap	Human(\"Human\");\nScavTrap	Assignment;\nAssignment = Human;" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "		↓" << std::endl;
	{
		ScavTrap	Human("Human");
		ScavTrap	Assignment;
		Assignment = Human;
	}
	std::cout << "\n-----------------------------------------" << std::endl;
	std::cout << "< TEST5" << std::endl;
	std::cout << "	  [ CODE ]" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "ScavTrap	Warrior(\"Warrior\")" << std::endl;
	std::cout << "ScavTrap	Monster(\"Monster\")\n" << std::endl;
	std::cout << "Warrior.AtackDamage(Monster);" << std::endl;
	std::cout << "Warrior.print_status();" << std::endl;
	std::cout << "Monster.print_status();" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "		↓" << std::endl;
	{
		ScavTrap	Warrior("Warrior");
		ScavTrap	Monster("Monster");

		Warrior.Atack_Damage(Monster);
		Warrior.print_status();
		Monster.print_status();
	}
	std::cout << "\n-----------------------------------------" << std::endl;
	std::cout << "< TEST6" << std::endl;
	std::cout << "	  [ CODE ]" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "ScavTrap	Human(\"Human\");\n" << std::endl;
	std::cout << "Human.guardGate();" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "		↓" << std::endl;
	{
		ScavTrap	Human("Human");

		Human.guardGate();
	}
	std::cout << "\n-----------------------------------------" << std::endl;
	return (0);
}
