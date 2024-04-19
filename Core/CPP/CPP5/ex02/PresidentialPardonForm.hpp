#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
	public:
		PresidentialPardonForm(std::string name);
		PresidentialPardonForm(PresidentialPardonForm const &rhs);
		PresidentialPardonForm &operator=(AForm const &rhs);
		~PresidentialPardonForm(void);

		void 		beSigned(Bureaucrat const &signer);
		void		execute(Bureaucrat const &signer, std::string const target) const;

	private:
		PresidentialPardonForm(void);
};
std::ostream &operator<<(std::ostream &o, AForm const &rhs);