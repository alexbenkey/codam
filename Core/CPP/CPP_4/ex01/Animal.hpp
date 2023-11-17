# pragma once
#include <iostream>
#include <string>
#include <memory>

class Animal{
	public:

		Animal(void);
		Animal(Animal const &rhs);
		Animal(std::string type);
		Animal &operator=(const Animal &rhs);
		virtual ~Animal(void);

		std::string getType(void) const;
		virtual void makeSound(void) const;

	protected:
		std::string _type;
};