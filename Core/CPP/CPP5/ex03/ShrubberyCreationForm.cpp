#include "ShrubberyCreationForm.hpp"
#include <fstream>  

ShrubberyCreationForm::ShrubberyCreationForm():AForm("", 145, 137){
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &rhs):AForm(rhs.get_name(), rhs.get_signGrade(), rhs.get_execGrade()){
	//std::cout << "ShrubberyCreationForm copy constructor  called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name): AForm(name, 145, 137){ 
	if (this->get_signGrade() < 1 || this->get_execGrade() < 1)
		throw ShrubberyCreationForm::GradeTooHighException();
	if (this->get_signGrade() > 150 || this->get_execGrade() > 150)
		throw ShrubberyCreationForm::GradeTooLowException();
	else{
		std::cout << "ShrubberyCreationForm with name: " << name << " has been constructed" << std::endl;
	}
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(AForm const &rhs){
	//std::cout << "copy constructor overload called" << std::endl;
	if (rhs.get_signGrade() < 1 || rhs.get_execGrade() < 1){
		throw ShrubberyCreationForm::GradeTooHighException();
		return (*this);
	}
	else if (rhs.get_signGrade() > 150 || rhs.get_execGrade() > 150){
		throw ShrubberyCreationForm::GradeTooLowException();
		return (*this);
	}
	else if (this != &rhs){
		ShrubberyCreationForm *inst = this;
		return (*inst);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){
	//std::cout << "ShrubberyCreationForm deconstructer called" << std::endl;
}

void ShrubberyCreationForm::beSigned(Bureaucrat const &signer){
	if (get_signed()){
		throw AlreadySignedException();
	}
	if(signer.get_grade() > get_signGrade()){
		throw GradeTooLowException();
	}
	else{
		this->sign();
		std::cout << "ShrubberyCreationForm " << this->get_name() << " has been signed by " << signer.get_name() << std::endl; 
	}
}

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &rhs){
	o << rhs.get_name() << " ShrubberyCreationForm has a sign grade of: " << std::to_string(rhs.get_signGrade()) << "and a exec grade of: " << std::to_string(rhs.get_execGrade()) << std::endl;
	return (o);
}

void ShrubberyCreationForm::execute(Bureaucrat const &signer, std::string const target) const{
	if(!this->get_signed())
		throw ShrubberyCreationForm::NotSignedException();
	if(signer.get_grade() > this->get_execGrade())
		throw ShrubberyCreationForm::GradeTooLowException();
	else{
		std::cout << "executing form!" << std::endl;
		std::ofstream outfile (target);
		outfile <<
"               ,@@@@@@@,				\n"
"       ,,,.   ,@@@@@@/@@,  .oo8888o.	\n"
"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o	\n"
"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'	\n"
"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'	\n"
"  %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'	\n"
"   `&%\\ ` /%&'    |.|        \\ '|8'	\n"
"       |o|        | |         | |		\n"
"       |.|        | |         | |		\n"
"  	 \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
		outfile.close();
	}
}