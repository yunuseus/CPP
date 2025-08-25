#include "ClapTrap.hpp"

int main()
{
	ClapTrap yunus("yunus");
	ClapTrap emre("emre");
	yunus.attack(emre.getName());
	yunus.beRepaired(3);
	std::cout << "yunus has " << yunus.getEnergyPoints() << " energy points" << std::endl;
	yunus.takeDamage(15);
	std::cout << "yunus has " << yunus.getHitPoints() << " hit points" << std::endl;
	ClapTrap alp = yunus;
	std::cout << "alp has " << alp.getEnergyPoints() << " energy points" << std::endl;
}