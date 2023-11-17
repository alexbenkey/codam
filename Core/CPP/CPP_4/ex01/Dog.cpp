#include "Dog.hpp"

Dog::Dog(void): Animal("Dog"){
	std::cout << this->_type << " constructor called" << std::endl;
	try{
		this->_Brain = new Brain();
	}
	catch (const std::bad_alloc& e) {
		std::cout << "Bad memory allocation ; " << e.what() << std::endl;
	}
}

Dog::Dog(std::string type){
	this->_type = type;
	std::cout << type << " has been constructed." << std::endl;
}

Dog::Dog(const Dog &rhs){
	std::cout << "Cat Copy c-tor" << std::endl;
	this->_type = rhs._type;
	this->_Brain = new Brain(*rhs._Brain);
}

Dog &Dog::operator=(const Dog &rhs){
	std::cout << "Dog Copy assigment operator" << std::endl;
	if (this != &rhs)
    {
        this->_type = rhs._type;
        this->_Brain = new Brain( *rhs._Brain );
    }
	return (*this);
}

Dog::~Dog(void){
	if (this->_Brain)
		delete this->_Brain;
	std::cout << "Dog has been destructed" << std::endl;
}

void	Dog::makeSound(void) const{
	std::cout << "'Woof Woof'" << std::endl;
}

void	Dog::print_brain(void) const{
	std::cout << "Brain address: " << &(this->_Brain) << std::endl;
	std::cout << "Brain first val: " << this->_Brain->get_idea(5) << std::endl;
}

void Dog::set_idea(int i, std::string idea){
	this->_Brain->set_idea(i, idea);
}