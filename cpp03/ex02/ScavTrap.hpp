#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap 
{
	public:
	ScavTrap();
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(const ScavTrap& other);
	void guardGate();
	
};