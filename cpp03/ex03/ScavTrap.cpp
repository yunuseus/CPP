#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "Default Scav constructor called" << std::endl;
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	this->name = "DefaultScav";
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
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

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
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

void ScavTrap::attack(const std::string& target)
{

	 if (this->EnergyPoints > 0 && this->HitPoints > 0)
    {
        this->EnergyPoints -= 1;
        std::cout << "ScavTrap " << this->name << " attacks " << target
                  << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "ScavTrap " << this->name << " can't attack (no energy or dead)" << std::endl;
    }
}
