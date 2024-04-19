#include "Form.hpp"

int main(void)
{
	Form *form_a = new Form("form_a", 100, 100);
	Form *form_b = new Form("form_b", 100, 100);
	Bureaucrat *bill = new Bureaucrat("bill", 99);
	bill->signForm(*form_a);
	bill->decrement_grade();
	bill->signForm(*form_a);
	bill->decrement_grade();
	bill->signForm(*form_a);
	bill->signForm(*form_b);
	delete form_a;
	delete form_b;
	delete bill;
}