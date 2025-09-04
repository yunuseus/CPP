#include "ScavTrap.hpp"

int main()
{
	ScavTrap yunus("yunus");
	ScavTrap emre("emre");

	std::cout << yunus.getAttackDamage() << std::endl;
	std::cout << yunus.getHitPoints() << std::endl;
	std::cout << yunus.getEnergyPoints() << std::endl;
	yunus.attack(emre.getName());
	emre.takeDamage(yunus.getAttackDamage());
	std::cout << emre.getHitPoints() << std::endl;
	std::cout << yunus.getEnergyPoints() << std::endl;
	emre.guardGate();
}