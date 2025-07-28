#include <iostream>

class Zombie 
{
    private:
        std::string name;
    public:

        Zombie();
        setName(std::string name);
        ~Zombie();
        void announce(void) const;
    };

Zombie* zombieHorde(int N, std::string name);
