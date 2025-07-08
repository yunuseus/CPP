void Zombie:: announce(void) const
{
    std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    name = name;
}
std::string Zombie::getName(void) const
{
    return name;
}