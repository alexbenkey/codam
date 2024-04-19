#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):AForm("", 72, 45){
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &rhs):AForm(rhs.get_name(), rhs.get_signGrade(), rhs.get_execGrade()){
}

RobotomyRequestForm::RobotomyRequestForm(std::string name): AForm(name, 72, 45){ 
	if (this->get_signGrade() < 1 || this->get_execGrade() < 1)
		throw RobotomyRequestForm::GradeTooHighException();
	if (this->get_signGrade() > 150 || this->get_execGrade() > 150)
		throw RobotomyRequestForm::GradeTooLowException();
	else{
		std::cout << "RobotomyRequestForm with name: " << name << " has been constructed" << std::endl;
	}
}


RobotomyRequestForm &RobotomyRequestForm::operator=(AForm const &rhs){
	std::cout << "copy constructor overload called" << std::endl;
	if (rhs.get_signGrade() < 1 || rhs.get_execGrade() < 1){
		throw GradeTooHighException();
		return (*this);
	}
	else if (rhs.get_signGrade() > 150 || rhs.get_execGrade() > 150){
		throw GradeTooLowException();
		return (*this);
	}
	else if (this != &rhs){
		RobotomyRequestForm *inst = this;
		return (*inst);
	}
	return (*this);
}
RobotomyRequestForm::~RobotomyRequestForm(void){
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void 	RobotomyRequestForm::beSigned(Bureaucrat const &signer){
	if(signer.get_grade() > get_signGrade())
		throw GradeTooLowException();
	else if(get_signed())
		throw AlreadySignedException();
	else{
		this->sign();
		std::cout << "RobotomyRequestForm " << this->get_name() << " has been signed by " << signer.get_name() << std::endl;
	}
}

void		RobotomyRequestForm::execute(Bureaucrat const &signer, std::string const target) const{
	if(signer.get_grade() > get_execGrade())
		throw GradeTooLowException();
	if(this->get_signed() == false)
		throw NotSignedException();
	else{
		std::cout << "RobotomyRequestForm " << this->get_name() << " has been executed by : " << signer.get_name() << std::endl;
		int r1 = rand() % 2;
		if (r1 == 0){
			std::cout << "buzz, drill, clamp, boop" << std::endl;
			std::cout << target << " has been robotomized " << std::endl;
		}
		else if (r1 == 1)
			std::cout << "robotomy failed" << std::endl;
	}
}
