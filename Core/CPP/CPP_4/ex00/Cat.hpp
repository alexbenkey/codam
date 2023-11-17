# pragma once

#include "Animal.hpp"

class Cat: public Animal{
	public:
		Cat(void);
		Cat(Cat const &rhs);
		Cat(std::string type);
		Cat &operator=(const Cat &rhs);
		~Cat(void);

		void makeSound(void) const;
	private:

};