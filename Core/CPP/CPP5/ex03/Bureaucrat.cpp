#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(void){
	//std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &rhs){
	//std::cout << "Bureaucrat copy constructor  called" << std::endl;
	Bureaucrat *inst = new Bureaucrat();
	inst->_name = rhs._name;
	inst->_grade = rhs._grade;
	inst->_max = rhs._max;
	inst->_min = rhs._min;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name){
	if (grade < this->_max)
		throw Bureaucrat::GradeTooHighException();
	if (grade > this->_min)
		throw Bureaucrat::GradeTooLowException();
	else{
		this->_grade = grade;
		std::cout << "Bureaucrat with name: " << name << " has been constructed" << std::endl;
	}
}

Bureaucrat &Bureaucrat::operator= (Bureaucrat const &rhs){
	//std::cout << "copy constructor overload called" << std::endl;
	if (rhs._grade < rhs._max){
		throw Bureaucrat::GradeTooHighException();
		return (*this);
	}
	else if (rhs._grade > rhs._min){
		throw Bureaucrat::GradeTooLowException();
		return (*this);
	}
	else if (this != &rhs){
		Bureaucrat *inst = new Bureaucrat();
		inst->_name = rhs._name;
		inst->_grade = rhs._grade;
		return (*inst);
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void){
	//std::cout << "Bureaucrat deconstructer called" << std::endl;
}

int Bureaucrat::get_grade(void) const{
	return(_grade);
}

std::string Bureaucrat::get_name(void) const{
	return(_name);
}

void Bureaucrat::set_grade(int grade){
	_grade = grade;
}

void Bureaucrat::increment_grade(void){
	if (_grade <= _max)
		throw Bureaucrat::GradeTooHighException();
	else
	{
		_grade--;
		std::cout << "Bureacrat has increased its grade to: " << _grade << std::endl;
	}
}

void Bureaucrat::decrement_grade(void){
	if (_grade >= _min)
		throw Bureaucrat::GradeTooLowException();
	else
	{
		_grade++;
		std::cout << "Bureacrat has decreased its grade to: " << _grade << std::endl;
	}
}

const char *Bureaucrat::AlreadySignedException::what() const throw(){
	return "form already signed";
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
	return "grade too high";
};

const char *Bureaucrat::GradeTooLowException::what() const throw(){
	return "grade too low";
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs){
	o << rhs.get_name() << " bureacrat grade: " << std::to_string(rhs.get_grade()) << std::endl;
	return (o);
};

void Bureaucrat::signForm(AForm &toSign){
	try{
		std::cout << "trying to sign " << toSign.get_name() << " by bureaucrat: " << this->get_name() << std::endl; 
		toSign.beSigned(*this);
	}
	catch (AForm::GradeTooLowException f){
		std::cout << f.what() << std::endl;
	}
	catch (AForm::AlreadySignedException f){
		std::cout << f.what() << std::endl;
	}
};

void Bureaucrat::executeForm(AForm const &form, std::string const target){
	try{
		form.execute(*this, target);
		std::cout << this->get_name() << " executed " << form.get_name() << std::endl;
	}
	catch (AForm::GradeTooLowException f){
		std::cout << f.what() << std::endl;
	}
	catch (AForm::NotSignedException f){
		std::cout << f.what() << std::endl;
	}
}