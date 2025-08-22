#include "ClapTrap.hpp"
#include  <iostream>
ClapTrap::ClapTrap()
{
	std::cout << "Default Constructor called"<< std::endl;
	this->name = "defaultClap";
	this->EnergyPoints = 10;
	this->HitPoints = 10;
	this->AttackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Construcotr called" << std::endl;
	this->name = name;
	this->EnergyPoints = 10;
	this->HitPoints = 10;
	this->AttackDamage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->EnergyPoints > 0 && this->HitPoints > 0)
		this->HitPoints -= amount;
}

