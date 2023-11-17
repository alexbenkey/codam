# pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal{
	public:
		Cat(void);
		Cat(Cat const &rhs);
		Cat(std::string type);
		Cat &operator=(const Cat &rhs);
		~Cat(void);
		void set_idea(int i, std::string idea);

		void print_brain(void) const;
		void makeSound(void) const;

	private:
		Brain *_Brain;

};