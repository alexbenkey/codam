# pragma once

#include "Animal.hpp"

class Dog: public Animal{
	public:
		Dog(void);
		Dog(Dog const &rhs);
		Dog(std::string const type);
		Dog &operator=(const Dog &rhs);
		~Dog(void);

		void makeSound(void) const;
	private:
};