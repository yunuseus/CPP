#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() :ClapTrap("Defaulclap"), FragTrap("DefaultFrag"), ScavTrap("DefaultScav"), name("DefaultDiamond")
{
	std::cout << "Default DiamondTrap constructor called";
	this->HitPoints = FragTrap::HitPoints;
	this->EnergyPoints = ScavTrap::EnergyPoints;
	this->AttackDamage = FragTrap::AttackDamage;
}


DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name)
{
	std::cout << "DiamondTrap constructor called";
	this->HitPoints = FragTrap::HitPoints;
	this->EnergyPoints = ScavTrap::EnergyPoints;
	this->AttackDamage = FragTrap::AttackDamage;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Diamond destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "Diamond copy assigment operator called" << std::endl;

	this->name = other.getName();
	this->AttackDamage = other.getAttackDamage();
	this->EnergyPoints = other.getEnergyPoints();
	this->HitPoints = other.getHitPoints();
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
{
	std::cout << "Diamond copy constructor called" << std::endl;
	*this = other;
}

