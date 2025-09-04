#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
	FragTrap();
	~FragTrap();
	FragTrap(std::string name);
	FragTrap& operator=(const FragTrap& other);
	FragTrap(const FragTrap& other);
	void highFivesGuys(void);
};