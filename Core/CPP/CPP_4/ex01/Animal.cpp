#include "Animal.hpp"

Animal::Animal(void): _type(""){
	std::cout << "animal has been constructed." << std::endl; 
}

Animal::Animal(std::string type): _type(type){
	std::cout << "animal with type: " << type << " has been constructed." << std::endl;
}

Animal::Animal(const Animal &rhs){
	std::cout << "Dog Copy constructor" << std::endl;
	*this = rhs;
}

Animal &Animal::operator=(const Animal &rhs){
	std::cout << "Animal Copy assigment operator" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

Animal::~Animal(void){
	std::cout << "Animal has been destructed" << std::endl;
}

std::string Animal::getType(void) const{
	return(_type);
}

void	Animal::makeSound(void) const{
	std::cout << "General animal does not make a sound" << std::endl;
}
