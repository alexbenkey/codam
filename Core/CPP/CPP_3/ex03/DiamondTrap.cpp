#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap("_clap_name"), ScavTrap(), FragTrap(){
    std::cout << "DiamondTrap was constructed" << std::endl << std::endl;
}

DiamondTrap::DiamondTrap(std::string const name): ClapTrap(name + "_clap_name"), _name(name)
{
    //this->_name = name;
    this->_healthpoints = FragTrap::get_defaulthp();
    this->_attackdamage = FragTrap::get_defaultad();
    this->_energypoints = ScavTrap::get_defaultep();

    std::cout << "DiamondTrap with name: " << this->get_name() << " was created." << std::endl;
    std::cout << "it has: " 
    << get_hp() << " hp" << std::endl
    << get_ep() << " energy points" << std::endl
    << get_ad() << " attack damage" << std::endl << std::endl;
}

std::string DiamondTrap::get_name(void) const{
    return (this->_name);
}

int   DiamondTrap::get_defaulthp(void) const{
    return (FragTrap::get_defaulthp());
}

int   DiamondTrap::get_defaultep(void) const{
    return (ScavTrap::get_defaultep());
}

int   DiamondTrap::get_defaultad(void) const{
    return (FragTrap::get_defaultad());
}

DiamondTrap::~DiamondTrap(void){
    std::cout << "DiamondTrap with name: " << this->get_name() << " was destroyed" << std::endl;
}

void DiamondTrap::WhoAmI(){
    std::cout << "my DiamondTrap name is: " << get_name() << std::endl;
    std::cout << "my ClapTrap name is: " << ClapTrap::get_name() << std::endl << std::endl;
}