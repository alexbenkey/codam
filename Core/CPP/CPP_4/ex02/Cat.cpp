#include "Cat.hpp"

Cat::Cat(void): A_Animal("Cat"){
	std::cout << this->_type << "constructor called" << std::endl;
    try {
        this->_Brain = new Brain();
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Bad memory allocation ; " << e.what() << std::endl;
    }
}

Cat::Cat(std::string type){
	this->_type = type;
	std::cout << type << " has been constructed." << std::endl;
}

Cat::Cat(const Cat &rhs){
	std::cout << "Cat Copy c-tor" << std::endl;
	this->_type = rhs._type;
	this->_Brain = new Brain(*rhs._Brain);
}

Cat &Cat::operator=(const Cat &rhs){
	std::cout << "Cat Copy assigment operator" << std::endl;
	if (this != &rhs)
	{	
		this->_type = rhs._type;
		this->_Brain = new Brain(*rhs._Brain);
	}
	return (*this);
}

Cat::~Cat(void){
	if (this->_Brain)
		delete this->_Brain;
	std::cout << "Cat has been destructed" << std::endl;
}

void	Cat::makeSound(void) const{
	std::cout << "'Miaaaauw'" << std::endl;
}

void	Cat::print_brain(void) const{
	std::cout << "Brain address: " << &_Brain << std::endl;
	std::cout << "Brain fifth val: " << this->_Brain->get_idea(5) << std::endl;
}

void Cat::set_idea(int i, std::string idea){
	this->_Brain->set_idea(i, idea);
}

std::string Cat::getType(void) const{
	return(_type);
}