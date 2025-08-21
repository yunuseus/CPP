#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
class ClapTrap{
	private:
		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int AttackDamage;
	public:
		ClapTrap();
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beReapired(unsigned int amount);
};

#endif