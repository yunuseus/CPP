#include "Zombie.hpp"
int main()
{
    Zombie zombie("yunus");
    zombie.announce();
	Zombie* horde = zombieHorde(5, "HordeZombie");
	for (int i = 0; i < 5; i++)
	{
		horde[i].announce();
	}
	delete[] horde;

    return 0;
}