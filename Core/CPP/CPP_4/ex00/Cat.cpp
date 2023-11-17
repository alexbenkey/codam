#include "Cat.hpp"

Cat::Cat(void): Animal("Cat"){

	std::cout << "Cat has been constructed." << std::endl; 
}

Cat::Cat(std::string type){
	this->_type = type;
	std::cout << type << " has been constructed." << std::endl;
}

Cat::Cat(const Cat &rhs){
	*this = rhs;
}

Cat &Cat::operator=(const Cat &rhs){
	this->_type = rhs._type;
	return (*this);
}

Cat::~Cat(void){
	std::cout << "Cat has been destructed" << std::endl;
}

void	Cat::makeSound(void) const{
	std::cout << "'Miaaaauw'" << std::endl;
}

