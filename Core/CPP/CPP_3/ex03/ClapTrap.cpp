#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name(""), _healthpoints(_defaultHP), _energypoints(_defaultEP), _attackdamage(_defaultAD)
{
    std::cout << "ClapTrap with name " << get_name() << " was created." << std::endl;
       std::cout << "it has: " 
    << get_hp() << " hp" << std::endl                        
    << get_ep() << " energy points" << std::endl
    << get_ad() << " attack damage" << std::endl << std::endl;
}

ClapTrap::ClapTrap(std::string const name): _name(name), _healthpoints(_defaultHP), _energypoints(_defaultEP), _attackdamage(_defaultAD)
{
    std::cout << "ClapTrap with name " << get_name() << " was created." << std::endl;
       std::cout << "it has: " 
    << get_hp() << " hp" << std::endl                        
    << get_ep() << " energy points" << std::endl
    << get_ad() << " attack damage" << std::endl << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &rhs){
    *this = rhs;
}

ClapTrap::ClapTrap(std::string const name, ClapTrap const &rhs){
    *this = rhs;
    set_name(name);
    std::cout << "ClapTrap with name: " << get_name() << " was created." << std::endl;
    std::cout << "it has: " 
    << get_hp() << " hp" << std::endl                        
    << get_ep() << " energy points" << std::endl
    << get_ad() << " attack damage" << std::endl << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap with name: " << this->_name << " was destroyed" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs){
    this->_name = rhs._name;
    this->_healthpoints = rhs._healthpoints;
    this->_energypoints = rhs._energypoints;
    this->_attackdamage = rhs._attackdamage;
    return (*this);
}

std::string     &ClapTrap::get_name(void){
    return (_name);
}

void    ClapTrap::set_name(std::string const &name){
    _name = name;
}

int    &ClapTrap::get_hp(void){
    return(_healthpoints);
}
void   ClapTrap::set_hp(int hp){
    _healthpoints = hp;
}

int    &ClapTrap::get_ep(void){
    return (_energypoints);
}

void   ClapTrap::set_ep(int ep){
    _energypoints = ep;
}
int    &ClapTrap::get_ad(void){
    return(_attackdamage);
}

void   ClapTrap::set_ad(int ad){
    _attackdamage = ad;
}

int   ClapTrap::get_defaulthp(void) const{
    return (_defaultHP);
}

int   ClapTrap::get_defaultep(void) const{
    return (_defaultEP);
}

int   ClapTrap::get_defaultad(void) const{
    return (_defaultAD);
}

void ClapTrap::attack(const std::string &target){
    if (get_hp() > 0 && get_ep() > 0){
        std::cout << "ClapTrap " << get_name() << " attacks " << target << " causing " << std::to_string(get_ad()) << " points of damage!" << std::endl << std::endl;
        this->_energypoints--; 
    }
    else if (get_hp() > 0)
        std::cout << "no energy points available." << std::endl << std::endl;  
    else if (get_hp() == 0 )
        std::cout << get_name() << " is dead, and cannot attack" << std::endl << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
    if ((unsigned int)get_hp() > amount){
        std::cout << get_name() << " took " << amount << " damage." << std::endl;
        get_hp () -= amount;
        std::cout << get_name() << " now has " << get_hp() << " health points" << std::endl << std::endl;
    }
    else{
        std::cout << get_name() << " is dead and can not take any more damage" << std::endl << std::endl;
        set_hp(0);
    }
}

void ClapTrap::beRepaired(unsigned int amount){
    if (get_hp() && get_ep()){
        std::cout << get_name() << " repaired itself for " << amount << " points of health." << std::endl << std::endl;
        set_hp(get_hp() + amount);
        this->_energypoints--;
        std::cout << "it now has " << get_hp() << " health points" << std::endl;
    }
    else if (get_hp())
        std::cout << get_name() << " does not have enough energy points to repair itself" << std::endl << std::endl;
    else if (get_hp() == 0)
        std::cout << get_name() << " is dead, and cannot be repaired" << std::endl << std::endl;
}
