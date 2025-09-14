#include "ClapTrap.hpp"
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
	std::cout << "Constructor called" << std::endl;
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
	if (this->HitPoints > 0)
	{
		if (amount >= this->HitPoints)
			this->HitPoints = 0;
		else
			this->HitPoints -= amount;
	}
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy assigment operator called" << std::endl;
	if (this != &other)
	{
		this->AttackDamage = other.getAttackDamage();
		this->EnergyPoints = other.getEnergyPoints();
		this->HitPoints = other.getHitPoints();
		this->name = other.getName();
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->EnergyPoints > 0 && this->HitPoints > 0)
    {
        this->EnergyPoints -= 1;
        std::cout << "ClapTrap " << this->name << " attacks " << target
                  << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << this->name << " can't attack (no energy or dead)" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->HitPoints > 0 && this->EnergyPoints > 0)
    {
        this->HitPoints += amount;
        this->EnergyPoints -= 1;
        std::cout << "ClapTrap " << this->name << " is repaired by "
                  << amount << " hit points" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << this->name << " can't repair (no energy or dead)" << std::endl;
    }
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