#include "Bureaucrat.hpp"

int main(void)
{
	try {
		Bureaucrat *bill = new Bureaucrat("bill", -5);
		delete bill;
	}
	catch (Bureaucrat::GradeTooLowException e){
		std::cout << e.what() << std::endl;	
	}
	catch(Bureaucrat::GradeTooHighException e){
		std::cout << e.what() << std::endl;		
	}
	try {
		Bureaucrat *bob = new Bureaucrat("bob", 200);
		delete bob;
	}
	catch (Bureaucrat::GradeTooLowException e){
		std::cout << e.what() << std::endl;	
	}
	catch(Bureaucrat::GradeTooHighException e){
		std::cout << e.what() << std::endl;		
	}
	try {
	Bureaucrat *tim = new Bureaucrat("tim", 100);
	for (int i = 0; i < 150; i++){
		try{
			tim->increment_grade();
		}
		catch(Bureaucrat::GradeTooHighException e){
			std::cout << e.what() << std::endl;	
		}
	}
	for (int i = 0; i < 150; i++){
		try{
			tim->decrement_grade();
		}
		catch(Bureaucrat::GradeTooLowException e){
			std::cout << e.what() << std::endl;		
		}
	}
		delete tim;
	}
	catch (Bureaucrat::GradeTooLowException e){
		std::cout << e.what() << std::endl;	
	}
	catch(Bureaucrat::GradeTooHighException e){
		std::cout << e.what() << std::endl;		
	}
}