#include <iostream>

class Zombie 
{
    private:
        std::string name;
    public:

        Zombie(std::string name);
        ~Zombie();
        void announce(void) const;
    };

Zombie* zombieHorde(int n, std::string name);
