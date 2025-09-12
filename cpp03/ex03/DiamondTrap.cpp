#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() :ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << "Default DiamondTrap constructor called";
	this->name = "DefaultDiamond";
	this->HitPoints = FragTrap::HitPoints;
	this->EnergyPoints = ScavTrap::EnergyPoints;
	this->AttackDamage = FragTrap::AttackDamage;
}


DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	std::cout << "DiamondTrap constructor called"<< std::endl;
	this->name = name;
	ClapTrap::name = name + "_clap_name";
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
	return *this;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
{
	std::cout << "Diamond copy constructor called" << std::endl;
	*this = other;
}

void DiamondTrap::whoAmI()
{
	std::cout << "my name is " << this->name << " my clap name is " << ClapTrap::name << std::endl;
}

