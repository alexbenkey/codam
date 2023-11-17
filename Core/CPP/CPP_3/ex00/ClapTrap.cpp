#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name(""), _hitpoints(10), _energypoints(10), _attack_damage(0), _maxhp(10){
	std::cout << "ClapTrap has been created" << std::endl;
}

ClapTrap::~ClapTrap(void){
	std::cout << "ClapTrap with name " << this->_name << " has been destroyed" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &rhs){
    *this = rhs;
}

ClapTrap::ClapTrap(std::string name){
	std::cout << "ClapTrap with name: '" << name << "' has been created." << std::endl;
	this->_name = name;
	this->_hitpoints = 10;
	this->_energypoints =  10;
	this->_attack_damage = 0; 
	this->_maxhp = 10;
}

int	 ClapTrap::potential(void){
	if (this->_hitpoints && this->_energypoints)
		return(1);
	std::cout << "Claptrap " << this->_name << " has no remaining energypoints or hitpoints in order to perform an action" << std::endl;
	return (0);
}

void ClapTrap::set_name(std::string name){
	this->_name = name;
}

std::string &ClapTrap::get_name(){
	return (this->_name);
}

void ClapTrap::attack(std::string &target){
	if (this->potential())
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
		this->_energypoints--;
	}
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs){
	this->_name = rhs._name;
	this->_hitpoints = rhs._hitpoints;
	this->_energypoints = rhs._energypoints;
	this->_attack_damage = rhs._attack_damage;
	this->_maxhp = rhs._maxhp;
	return *this;
}

void ClapTrap::takeDamage (unsigned int amount){
	std::cout << "Claptrap " << this->_name << " takes " << amount << " damage" << std::endl;
	this->_hitpoints -= amount;
	if (this->_hitpoints <= 0)
		this->_hitpoints = 0;
	std::cout << "Claptrap " << this->_name << " currently has " << this->_hitpoints << " HP" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->potential())
	{
		this->_hitpoints += amount;
		if (this->_hitpoints > this->_maxhp)
			this->_hitpoints = this->_maxhp;
		this->_energypoints--;
		std::cout << "ClapTrap " << this->get_name() << " healed itself for " << amount << " health." << std::endl;	
	}
}