#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA{
    private:
            const std::string name;
            Weapon& weapon;
    public:
        HumanA(std::string name, Weapon& weapon);
        const std::string getName() const;
        const Weapon getWeapon();
        void attack();
};

#endif