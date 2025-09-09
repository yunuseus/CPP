#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "Frag default constructor called" << std::endl;
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
	this->name = "DefaultFrag";
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "Frag constructor called" << std::endl;
	this->name = name;
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "Frag Destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
{
	std::cout << "Frag copy constructor called" << std::endl;
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "Frag copy assigment operator called" << std::endl;
	if (this != &other)
	{
		this->AttackDamage = other.getAttackDamage();
		this->EnergyPoints = other.getEnergyPoints();
		this->HitPoints = other.getHitPoints();
		this->name = other.getName();
	}
	return *this;
}

void highFivesGuys(void)
{
	std::cout << "a positive high-fives request" << std::endl;
}
