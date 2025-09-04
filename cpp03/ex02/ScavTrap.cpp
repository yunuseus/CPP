#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "Default Scav constructor called" << std::endl;
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	this->name = "DefaultScav";
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "Scav constructor called" << std::endl;
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	this->name = name;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Scav Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
	std::cout << "Scav copy constructor called" << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "Scav copy assigment operator called" << std::endl;
	if (this != &other)
	{
		this->AttackDamage = other.getAttackDamage();
		this->EnergyPoints = other.getEnergyPoints();
		this->HitPoints = other.getHitPoints();
		this->name = other.getName();
	}
	return *this;
}

void ScavTrap::guardGate()
{
	std::cout << this->name <<" is now in Gate keeper mode." << std::endl;
}
