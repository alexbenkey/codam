#pragma once

#include <iostream>
#include <stdexcept>

class Bureaucrat{
	public:

		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &rhs);
		Bureaucrat &operator=(Bureaucrat const &rhs);
		~Bureaucrat(void);

		void		set_grade(int grade);
		int			get_grade(void) const;
		std::string	get_name(void) const;
		void		increment_grade(void);
		void		decrement_grade(void);

		class GradeTooHighException: public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException: public std::exception{
			public:
				virtual const char *what() const throw();
		};

	private:

		std::string		 	_name;
		int 				_grade;
		int					_max = 1;
		int					_min = 150;
};
std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);
