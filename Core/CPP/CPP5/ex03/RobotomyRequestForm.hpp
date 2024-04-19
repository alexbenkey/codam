#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm{
	public:

		RobotomyRequestForm(std::string name);
		RobotomyRequestForm(RobotomyRequestForm const &rhs);
		RobotomyRequestForm &operator=(AForm const &rhs);
		~RobotomyRequestForm(void);

		void 		beSigned(Bureaucrat const &signer);
		void		execute(Bureaucrat const &signer, std::string const target) const;

	private:
		RobotomyRequestForm(void);
};
std::ostream &operator<<(std::ostream &o, AForm const &rhs);