#include "Claptrap.hpp"

Claptrap::Claptrap(void): _hitpoints(10), _energypoints(10), _Attack_damage(0), _maxhp(10){
	std::cout << "Claptrap has been created" << std::endl;
}

Claptrap::~Claptrap(void){
	std::cout << "Claptrap has been destroyed" << std::endl;
}

Claptrap::Claptrap(std::string name){
	std::cout << "Claptrap with name: '" << name << "' has been created." << std::endl;
	this->_name = name;
}

int	 Claptrap::Potential(void){
	if (this->_hitpoints && !this->_energypoints)
		return(1);
	std::cout << "Claptrap is not available for attack" << std::endl;
	return (0);
}

void Claptrap::set_name(std::string name){
	this->_name = name;
}

std::string &Claptrap::get_name(){
	return (this->_name);
}

void Claptrap::attack(std::string &target){
	if (this->Potential())
	{
		std::cout << "Claptrap " << this->_name << " attacks " << target << ", causing " << this->_Attack_damage << "points of damage!" << std::endl;
		this->_energypoints--;
	}
}

Claptrap &Claptrap::operator=(Claptrap const &rhs){
	this->_name = rhs._name;
	this->_hitpoints = rhs._hitpoints;
	this->_energypoints = rhs._energypoints;
	this->_Attack_damage = rhs._Attack_damage;
	this->_maxhp = rhs._maxhp;
	return *this;
}

void Claptrap::takeDamage (unsigned int amount){
	this->_hitpoints -= amount;
	if (this->_hitpoints > this->_maxhp)
		this->_hitpoints = this->_maxhp;
}

void Claptrap::beRepaired(unsigned int amount){
	if (this->Potential())
	{
		this->_hitpoints += amount;
		if (this->_hitpoints > this->_maxhp)
			this->_hitpoints = this->_maxhp;
		std::cout << "Claptrap healed itself for " << amount << "health." << std::endl;	
	}
}