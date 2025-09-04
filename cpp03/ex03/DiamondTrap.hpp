#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : virtual FragTrap, virtual ScavTrap
{
	public:
		DiamondTrap();
		~DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap& operator=(const DiamondTrap& other);
};