#include "Zombie.hpp"


void Zombie::announce(void)
{
    std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{

}

void Zombie::setName(std::string name)
{
    this->name = name;
}
Zombie::~Zombie()
{
    std::cout << name << " is destroyed." << std::endl;
}