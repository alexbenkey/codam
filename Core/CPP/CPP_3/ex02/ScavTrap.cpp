#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{ 
    std::cout << "ScavTrap was constructed" << std::endl << std::endl << std::endl;
}

ScavTrap::ScavTrap(std::string const name): ClapTrap(name)
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
        std::cout << "ScavTrap " << this->get_name() << " attacks " << target << " causing " << std::endl << std::to_string(this->get_ad()) << " points of damage!" << std::endl;
        set_ep(this->get_ep() - 1); 
    }
    else if (this->get_ep() > 0)
        std::cout << "no energy points available." << std::endl << std::endl;  
    else if (this->get_ep() == 0)
        std::cout << this->get_name() << " is dead, and cannot attack" << std::endl << std::endl;
}

void ScavTrap::guardGate(){
    std::cout << "ScavTrap " << get_name() << " is now in guard mode" << std::endl;
}