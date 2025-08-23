#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
class ClapTrap{
	private:
		std::string name;
		unsigned int HitPoints;
		unsigned int EnergyPoints;
		unsigned int AttackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap(const ClapTrap& other);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beReapired(unsigned int amount);
		ClapTrap& operator=(const ClapTrap& other);
		unsigned int getHitPoints() const;
		unsigned int getEnergyPoints() const;
		unsigned int getAttackDamage() const;
		std::string getName() const;
};

#endif