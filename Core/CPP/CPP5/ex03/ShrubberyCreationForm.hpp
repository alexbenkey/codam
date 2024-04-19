#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm{
	public:

		ShrubberyCreationForm(std::string name);
		ShrubberyCreationForm(ShrubberyCreationForm const &rhs);
		ShrubberyCreationForm &operator=(AForm const &rhs);
		~ShrubberyCreationForm(void);

		void 		beSigned(Bureaucrat const &signer);
		void		execute(Bureaucrat const &signer, std::string const target) const;

	private:
		ShrubberyCreationForm(void);

};
std::ostream &operator<<(std::ostream &o, AForm const &rhs);