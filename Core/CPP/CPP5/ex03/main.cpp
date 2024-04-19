#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern *geoff = new Intern("Geoff");;
	AForm *form_a = geoff->makeForm("ShrubberyCreationForm", "form_a");
	AForm *form_b = geoff->makeForm("ShrubberyCreationForm", "form_b");
	AForm *form_r1 = geoff->makeForm("RobotomyRequestForm", "form_r1");
	AForm *form_p1 = geoff->makeForm("PresidentialPardonForm", "form_p1");


	Bureaucrat *bill = new Bureaucrat("bill", 101);
	Bureaucrat *tim = new Bureaucrat("tim", 99);
	Bureaucrat *alpha = new Bureaucrat("alpha", 1);
	bill->signForm(*form_a);
	bill->increment_grade();
	bill->signForm(*form_a);
	bill->increment_grade();
	bill->signForm(*form_a);
	bill->signForm(*form_b);
	bill->executeForm(*form_a, "frontlawn");
	bill->executeForm(*form_b, "backyard");
	tim->executeForm(*form_a, "frontlawn");
	alpha->signForm(*form_r1);
	alpha->executeForm(*form_r1, "a");
	alpha->executeForm(*form_r1, "b");
	alpha->executeForm(*form_r1, "c");
	alpha->executeForm(*form_r1, "d");
	alpha->executeForm(*form_r1, "e");
	alpha->executeForm(*form_r1, "f");
	alpha->executeForm(*form_r1, "g");
	alpha->executeForm(*form_r1, "h");
	alpha->executeForm(*form_r1, "i");
	alpha->executeForm(*form_r1, "j");
	alpha->executeForm(*form_r1, "k");
	alpha->executeForm(*form_r1, "l");
	alpha->executeForm(*form_r1, "m");
	alpha->executeForm(*form_r1, "n");
	alpha->executeForm(*form_r1, "o");
	alpha->executeForm(*form_r1, "p");
	alpha->executeForm(*form_r1, "q");
	alpha->executeForm(*form_r1, "r");
	alpha->executeForm(*form_r1, "s");
	alpha->executeForm(*form_r1, "t");
	alpha->signForm(*form_p1);
	alpha->executeForm(*form_p1, "donnie trump");

	delete form_p1;
	delete form_r1;
	delete form_a;
	delete form_b;
	delete bill;
	delete tim;
	delete alpha;
	delete geoff;
}