#include <iostream>

class Zombie 
{
    private:
        std::string name;
    public:

        Zombie();
        Zombie(std::string name);
        ~Zombie();
        void announce(void) const;
    };

Zombie* zombieHorde(int N, std::string name);
