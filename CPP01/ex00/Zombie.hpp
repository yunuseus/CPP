#include 
class Zombie 
{
    private:
        std::string name;
    public:
        Zombie(std::string name);
        ~Zombie();
        void announce(void) const;
        void setName(std::string name);
        std::string getName(void) const;
} 
