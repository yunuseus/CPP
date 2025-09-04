#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
#include  <iostream>

class ClapTrap{
	protected:
		std::string name;
		unsigned int HitPoints;
		unsigned int EnergyPoints;
		unsigned int AttackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap& operator=(const ClapTrap& other);
		ClapTrap(const ClapTrap& other);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		unsigned int getHitPoints() const;
		unsigned int getEnergyPoints() const;
		unsigned int getAttackDamage() const;
		std::string getName() const;
};

#endif