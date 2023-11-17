# pragma once
#include <iostream>
#include <string>

class Brain{
	public:

		Brain(void);
		Brain(Brain const &rhs);
		Brain &operator=(const Brain &rhs);
		virtual ~Brain(void);
		std::string get_idea(int i);
		void set_idea(int i, std::string idea);

	protected:

		std::string _ideas[100];
};