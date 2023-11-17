#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _type(""){
	std::cout << "WrongAnimal has been constructed." << std::endl; 
}

WrongAnimal::WrongAnimal(std::string type){
	this->_type = type;
	std::cout << "WrongAnimal with type: " << type << " has been constructed." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &rhs){
	*this = rhs;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs){
	this->_type = rhs._type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const{
	std::cout << "Wrong animal sound" << std::endl;
}

std::string WrongAnimal::getType(void) const{
	return(_type);
}

WrongAnimal::~WrongAnimal(void){
	std::cout << "WrongAnimal has been destructed" << std::endl;
}