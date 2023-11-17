# pragma once
#include <iostream>
#include <string>

class WrongAnimal{
	public:

		WrongAnimal(void);
		WrongAnimal(WrongAnimal const &rhs);
		WrongAnimal(std::string type);
		WrongAnimal &operator=(const WrongAnimal &rhs);
		virtual ~WrongAnimal(void);

		std::string getType(void) const;
		void	makeSound(void) const;

	protected:

		std::string _type;
};