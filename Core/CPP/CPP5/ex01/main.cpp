#include "Form.hpp"

int main(void)
{
	try {
		Bureaucrat *bill = new Bureaucrat("bill", 40);
		try{
			Form *form_a = new Form("form_a", 100, 100);
			try{
				bill->signForm(*form_a);
				bill->signForm(*form_a);
			}
			catch (Form::GradeTooLowException g){
				std::cout << g.what() << std::endl;
			}
			delete form_a;
		}
		catch (Form::GradeTooLowException f){
			std::cout << f.what() << std::endl;
		}
		catch (Form::GradeTooHighException f){
			std::cout << f.what() << std::endl;
		}
		delete bill;
	}
	catch (Bureaucrat::GradeTooLowException e){
		std::cout << e.what() << std::endl;	
	}
	catch(Bureaucrat::GradeTooHighException e){
		std::cout << e.what() << std::endl;		
	}

}