#include "Form.hpp"

Form::Form(Form const &rhs):Form(rhs._name, rhs._signGrade, rhs._execGrade){
	std::cout << "Form copy constructor  called" << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade): _name(name), _signGrade(signGrade), _execGrade(execGrade){
	if (_signGrade < 1 || _execGrade < 1)
		throw Form::GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw Form::GradeTooLowException();
	else{
		_signed = 0;
		std::cout << "Form with name: " << name << " has been constructed" << std::endl;
	}
}

Form &Form::operator= (Form const &rhs){
	std::cout << "copy constructor overload called" << std::endl;
	if (rhs._signGrade < 1 || rhs._execGrade < 1){
		throw Form::GradeTooHighException();
		return (*this);
	}
	else if (rhs._signGrade > 150 || rhs._execGrade > 150){
		throw Form::GradeTooLowException();
		return (*this);
	}
	else if (this != &rhs){
		Form *inst = new Form(rhs._name, rhs._signGrade, rhs._execGrade);
		return (*inst);
	}
	return (*this);
}

Form::~Form(void){
	std::cout << "Form deconstructer called" << std::endl;
}

int 	Form::get_signGrade(void) const{
	return(_signGrade);
}

int 	Form::get_execGrade(void) const{
	return(_execGrade);
}

std::string Form::get_name(void) const{
	return(_name);
}

bool Form::get_signed() const{
	return _signed;
}

const char *Form::GradeTooHighException::what() const throw(){
	return "grade too high";
};

const char *Form::GradeTooLowException::what() const throw(){
	return "grade too low";
};

void Form::beSigned(Bureaucrat const &signer){
	if(signer.get_range() > _signGrade){
		throw Form::GradeTooLowException();
	}
	if(signer)
	_signed = 1;
}

std::ostream &operator<<(std::ostream &o, Form const &rhs){
	o << rhs.get_name() << " Form has a sign grade of: " << std::to_string(rhs.get_signGrade()) << "and a exec grade of: " << std::to_string(rhs.get_execGrade()) << std::endl;
	return (o);
}