#include "Zombie.hpp"


void Zombie::announce(void) const
{
    std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{
    name = "defaultZombie";
}

void Zombie::setName(std::string name)
{
    this->name = name;
}
Zombie::~Zombie()
{
    std::cout << name << " is destroyed." << std::endl;
}