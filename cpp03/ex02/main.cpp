#include "FragTrap.hpp"

int main()
{
	FragTrap emre("emre");
	FragTrap yunus("yunus");
	std::cout << emre.getName() << std::endl;
	std::cout << emre.getAttackDamage() << std::endl;
	std::cout << emre.getEnergyPoints() << std::endl;
	std::cout << emre.getHitPoints() << std::endl;
	yunus.attack("emre");
	emre.takeDamage(yunus.getAttackDamage());
	std::cout << emre.getHitPoints() << std::endl;
	emre.highFivesGuys();
}