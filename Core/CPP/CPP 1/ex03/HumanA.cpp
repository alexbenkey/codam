#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon):_weapon(weapon)
{
    this->_name = name;
    std::cout << "HumanA has been constructed" << std::endl;
}

HumanA::~HumanA(void)
{
    std::cout << "HumanA has been destructed" << std::endl;
}

Weapon &HumanA::getWeapon(void)
{
    return (this->_weapon);
}

std::string HumanA::getName(void)
{
    return (this->_name);
}

void HumanA::attack(void)
{
    std::cout << HumanA::getName() << " attacks with their weapon " << this->_weapon.getType() << std::endl;
}
