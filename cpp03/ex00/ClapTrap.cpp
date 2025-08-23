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
	{
		if (amount >= this->HitPoints)
			this->HitPoints = 0;
		else
			this->HitPoints -= amount;
	}
}

ClapTrap::ClapTrap(const ClapTrap& clap)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = clap;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clap)
{
	std::cout << "Copy assigment operator called" << std::endl;
	if (this != &clap)
	{
		this->AttackDamage = clap.getAttackDamage();
		this->EnergyPoints = clap.getEnergyPoints();
		this->HitPoints = clap.getHitPoints();
		this->name = clap.getName();
	}
	return *this;
}
std::string ClapTrap::getName() const
{
	return this->name;
}
unsigned int ClapTrap::getAttackDamage() const
{
	return this->AttackDamage;
}

unsigned int ClapTrap::getHitPoints() const
{
	return this->HitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return this->EnergyPoints;
}