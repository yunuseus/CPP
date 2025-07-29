#include "HumanA.hpp"
#include <iostream>
HumanA::HumanA(std::string name, Weapon& weapon) : name(name) , weapon(weapon)
{

}
const Weapon HumanA::getWeapon()
{
	return weapon;
}
void HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}