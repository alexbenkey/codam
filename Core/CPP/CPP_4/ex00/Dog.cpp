#include "Dog.hpp"

Dog::Dog(void): Animal("Dog"){
	std::cout << "Dog has been constructed." << std::endl; 
}

Dog::Dog(std::string type){
	this->_type = type;
	std::cout << type << " has been constructed." << std::endl;
}

Dog::Dog(const Dog &rhs){
	*this = rhs;
}

Dog &Dog::operator=(const Dog &rhs){
	this->_type = rhs._type;
	return (*this);
}

void	Dog::makeSound(void) const{
	std::cout << "'Woof Woof'" << std::endl;
}

Dog::~Dog(void){
	std::cout << "Dog has been destructed" << std::endl;
}