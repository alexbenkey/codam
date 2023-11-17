#include "Brain.hpp"

Brain::Brain(void){
	for (int i = 0; i < 100; i++){
		_ideas[i] = "I need some food! " + std::to_string(i);
	}
	std::cout << "Brain has been constructed." << std::endl; 
}

Brain::Brain(const Brain &rhs){
	std::cout << "Brain c-tor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = rhs._ideas[i];
	// /*this = rhs;
}

Brain &Brain::operator=(const Brain &rhs){
	std::cout << "Brain copy assignment overload called" << std::endl;
	std::string *ideas = new std::string(*rhs._ideas);
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = ideas[i];
	return (*this);
}

Brain::~Brain(void){
	std::cout << "Brain has been destructed" << std::endl;
}

void Brain::set_idea(int i, std::string idea){
	this->_ideas[i] = idea;
}

std::string Brain::get_idea(int i){
	return(this->_ideas[i]);
}
