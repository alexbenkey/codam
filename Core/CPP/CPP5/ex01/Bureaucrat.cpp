#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void){
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &rhs){
	std::cout << "Bureaucrat copy constructor  called" << std::endl;
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
	std::cout << "copy constructor overload called" << std::endl;
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
	std::cout << "Bureaucrat deconstructer called" << std::endl;
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

const char *Bureaucrat::GradeTooHighException::what() const throw(){
	return "grade too high";
};

const char *Bureaucrat::GradeTooLowException::what() const throw(){
	return "grade too low";
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs){
	o << rhs.get_name() << " bureacrat grade: " << std::to_string(rhs.get_grade()) << std::endl;
	return (o);
}

void Bureaucrat::signForm(Form &toSign){
	try{
		toSign.beSigned(*this);
	// move exceptions to beSigned so that they do not need to be cought in main.
	// make general exception function 
	}
	if (_grade > toSign.get_signGrade()){
		throw Form::GradeTooLowException();
	}
	if(toSign.get_signed()){
		std::cout << "this form has already been signed" << std::endl;
		return ;
	}
	else{
		toSign.beSigned(*this);
		std::cout << "form " << toSign.get_name() << " has been signed by " << _name << std::endl; 
	}
}	