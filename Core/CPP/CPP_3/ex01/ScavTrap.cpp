#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap(), _gatemode(0)
{ 
    std::cout << "ScavTrap was constructed" << std::endl << std::endl;
}

ScavTrap::ScavTrap(std::string const name): ClapTrap(name), _gatemode(0)
{ 
    this->set_hp(100);
    this->set_ep(50);
    this->set_ad(20);

    std::cout << "ScavTrap with name: " << this->get_name() << " was created." << std::endl;
    std::cout << "it has: " 
    << get_hp() << " hp" << std::endl                        
    << get_ep() << " energy points" << std::endl
    << get_ad() << " attack damage" << std::endl << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap with name: " << this->get_name() << " was destroyed" << std::endl;
}

void ScavTrap::attack(const std::string &target){
    if (this->get_hp() > 0 && this->get_ep() > 0){
        std::cout << "ScavTrap " << this->get_name() << " attacks " << target << " causing " << std::to_string(this->get_ad()) << " points of damage!" << std::endl;
        set_ep(this->get_ep() - 1); 
    }
    else if (this->get_ep() > 0)
        std::cout << "no energy points available." << std::endl << std::endl;  
    else if (this->get_ep() == 0)
        std::cout << this->get_name() << " is dead, and cannot attack" << std::endl << std::endl;
}

void ScavTrap::guardGate(){
    std::cout << "ScavTrap " << get_name() << " is now in guard mode" << std::endl << std::endl;
    this->_gatemode = 1;
}

void ScavTrap::takeDamage(unsigned int amount){
    if ((unsigned int)get_hp() > amount){
        if (this->_gatemode)
        {
            std::cout << "ScavTrap " << this->_name << " is in guard mode, it takes less damage." << std::endl;
            amount = amount / 2;
        }
        std::cout << get_name() << " took " << amount << " damage." << std::endl;
        get_hp () -= amount;
        std::cout << get_name() << " now has " << get_hp() << " health points" << std::endl << std::endl;
    }
    else{
        std::cout << get_name() << " is dead and can not take any more damage" << std::endl << std::endl;
        set_hp(0);
    }
}