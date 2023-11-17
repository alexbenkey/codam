# pragma once

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
	public:
		WrongCat(void);
		WrongCat(WrongCat const &rhs);
		WrongCat(std::string type);
		WrongCat &operator=(const WrongCat &rhs);
		~WrongCat(void);

		void	makeSound(void) const;

	private:
		std::string _type;

};