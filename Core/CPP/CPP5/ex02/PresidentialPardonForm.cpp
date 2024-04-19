#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):AForm("", 25, 5){
	std::cout << "PresidentialPardonForm constructor called. " << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name):AForm(name, 25, 5){
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &rhs):AForm(rhs.get_name(), rhs.get_signGrade(), rhs.get_execGrade()){ 
}

PresidentialPardonForm  &PresidentialPardonForm::operator=(AForm const &rhs){
	if (rhs.get_signGrade() < 1 || rhs.get_execGrade() < 1){
		throw GradeTooHighException();
		return (*this);
	}
	else if (rhs.get_signGrade() > 150 || rhs.get_execGrade() > 150){
		throw GradeTooLowException();
		return (*this);
	}
	else if (this != &rhs){
		PresidentialPardonForm *inst = this;
		return (*inst);
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void){
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void 		PresidentialPardonForm::beSigned(Bureaucrat const &signer){
	if(signer.get_grade() > get_signGrade())
		throw GradeTooHighException();
	else if(get_signed())
		throw AlreadySignedException();
	else{
		this->sign();
		std::cout << "PresidentialPardonForm " << this->get_name() << " has been signed by " << signer.get_name() << std::endl;
	}
}

void		PresidentialPardonForm::execute(Bureaucrat const &signer, std::string const target) const{
	if(signer.get_grade() > get_signGrade())
		throw GradeTooHighException();	
	else if(!get_signed())
		throw NotSignedException();
	else
		std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}