#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : virtual public FragTrap, virtual public ScavTrap, virtual public ClapTrap
{
	private:
		std::string name;
	public:
		DiamondTrap();
		~DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap& operator=(const DiamondTrap& other);

		using ScavTrap::attack;
		using FragTrap::HitPoints;
		using ScavTrap::EnergyPoints;
		using FragTrap::AttackDamage;

};