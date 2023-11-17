#include "A_Animal.hpp"

A_Animal::A_Animal(void): _type(""){
	std::cout << "A_Animal has been constructed." << std::endl; 
}

A_Animal::A_Animal(std::string type): _type(type){
	std::cout << "A_Animal with type: " << type << " has been constructed." << std::endl;
}

A_Animal::A_Animal(const A_Animal &rhs){
	std::cout << "Dog Copy constructor" << std::endl;
	*this = rhs;
}

A_Animal &A_Animal::operator=(const A_Animal &rhs){
	std::cout << "A_Animal Copy assigment operator" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

A_Animal::~A_Animal(void){
	std::cout << "A_Animal has been destructed" << std::endl;
}

std::string A_Animal::getType(void) const{
	return(_type);
}

void	A_Animal::makeSound(void) const{
	std::cout << "General A_Animal does not make a sound" << std::endl;
}
