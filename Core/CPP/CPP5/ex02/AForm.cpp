#include "AForm.hpp"

AForm::AForm(AForm const &rhs):AForm(rhs._name, rhs._signGrade, rhs._execGrade){
	std::cout << "AForm copy constructor  called" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade): _name(name), _signGrade(signGrade), _execGrade(execGrade){
	if (_signGrade < 1 || _execGrade < 1)
		throw AForm::GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw AForm::GradeTooLowException();
	else{
		_signed = 0;
		std::cout << "AForm with name: " << name << " has been constructed" << std::endl;
	}
}

AForm &AForm::operator= (AForm const &rhs){
	std::cout << "copy constructor overload called" << std::endl;
	if (rhs._signGrade < 1 || rhs._execGrade < 1){
		throw AForm::GradeTooHighException();
		return (*this);
	}
	else if (rhs._signGrade > 150 || rhs._execGrade > 150){
		throw AForm::GradeTooLowException();
		return (*this);
	}
	else if (this != &rhs){
		AForm *inst = this;
		return (*inst);
	}
	return (*this);
}

AForm::~AForm(void){
	//std::cout << "AForm deconstructer called" << std::endl;
}

void	AForm::sign(void){
	this->_signed = 1;
}

int 	AForm::get_signGrade(void) const{
	return(_signGrade);
}

int 	AForm::get_execGrade(void) const{
	return(_execGrade);
}

std::string AForm::get_name(void) const{
	return(_name);
}

bool AForm::get_signed() const{
	return _signed;
}

const char *AForm::NotSignedException::what() const throw(){
	return "Form needs to be signed before it can be executed";
}

const char *AForm::GradeTooHighException::what() const throw(){
	return "grade too high";
};

const char *AForm::GradeTooLowException::what() const throw(){
	return "grade too low";
};

const char *AForm::AlreadySignedException::what() const throw(){
	return "AForm already signed";
}

void AForm::beSigned(Bureaucrat const &signer){
	if (this->_signed)
		throw AlreadySignedException();
	if(signer.get_grade() > _signGrade){
		throw GradeTooLowException();
	}
	else{
		_signed = true;
		std::cout << this->_name << " has been signed by " << signer.get_name() << std::endl; 
	}
}

void AForm::execute(Bureaucrat const &signer, std::string const target) const{
	if (!this->_signed)
		throw NotSignedException();
	if (signer.get_grade() > _execGrade)
		throw GradeTooLowException(); 
	else
		std::cout << this->_name <<" form, with target: " << target << " has been executed by " << signer.get_name() << std::endl;
}

std::ostream &operator<<(std::ostream &o, AForm const &rhs){
	o << rhs.get_name() << " AForm has a sign grade of: " << std::to_string(rhs.get_signGrade()) << "and a exec grade of: " << std::to_string(rhs.get_execGrade()) << std::endl;
	return (o);
}