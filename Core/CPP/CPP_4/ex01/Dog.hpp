# pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal{
	public:
		Dog(void);
		Dog(Dog const &rhs);
		Dog(std::string const type);
		Dog &operator=(const Dog &rhs);
		~Dog(void);

		void print_brain(void) const;
		void makeSound(void) const;
		void set_idea(int i, std::string idea);

	private:
		Brain *_Brain;
};