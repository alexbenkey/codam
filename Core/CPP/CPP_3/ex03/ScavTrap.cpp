#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{ 
    _healthpoints = this->_defaultHP;
    _energypoints = this->_defaultEP;
    _attackdamage = this->_defaultAD;

    std::cout << "ScavTrap was constructed" << std::endl << std::endl << std::endl;
}

ScavTrap::ScavTrap(std::string const name): ClapTrap(name)
{ 
    this->_healthpoints = this->get_defaulthp();
    this->_energypoints = this->get_defaultep();
    this->_attackdamage = this->get_defaultad();

    std::cout << "ScavTrap with name: " << this->get_name() << " was created." << std::endl;
    std::cout << "it has: " 
    << get_hp() << " hp" << std::endl                        
    << get_ep() << " energy points" << std::endl
    << get_ad() << " attack damage" << std::endl << std::endl;
}

int   ScavTrap::get_defaulthp(void) const{
    return (this->_defaultHP);
}

int   ScavTrap::get_defaultep(void) const{
    return (_defaultEP);
}

int   ScavTrap::get_defaultad(void) const{
    return (_defaultAD);
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