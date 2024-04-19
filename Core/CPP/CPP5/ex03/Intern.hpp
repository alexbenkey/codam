#include "AForm.hpp"

class Intern{
	public:
		Intern(void);
		Intern(const Intern &rhs);
		Intern(const std::string name);
		Intern &operator=(Intern const &rhs);
		~Intern(void);

		AForm *makeForm(std::string const formName, std::string const target);

	private:
		std::string _name;
};