#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat"){

	std::cout << "WrongCat has been constructed." << std::endl; 
}

WrongCat::WrongCat(std::string type){
	this->_type = type;
	std::cout << "WrongCat with type: " << type << " has been constructed." << std::endl;
}

WrongCat::WrongCat(const WrongCat &rhs){
	*this = rhs;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs){
	this->_type = rhs._type;
	return (*this);
}

void	WrongCat::makeSound(void) const{
	std::cout << "'oink oink'" << std::endl;
}

WrongCat::~WrongCat(void){
	std::cout << "WrongCat has been destructed" << std::endl;
}