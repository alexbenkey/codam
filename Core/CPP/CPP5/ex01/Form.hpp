#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form{
	public:

		Form(std::string name, int signGrade, int execGrade);
		Form(Form const &rhs);
		Form &operator=(Form const &rhs);
		~Form(void);

		//void		set_range(int range);
		std::string get_name(void) const;
		bool		get_signed(void) const;
		int			get_signGrade(void) const;
		int			get_execGrade(void) const;

		void 		beSigned(Bureaucrat const &signer);

		class AlreadySignedException: public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooHighException: public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException: public std::exception{
			public:
				virtual const char *what() const throw();
		};

	private:
		Form(void);
		std::string	const	 	_name;
		bool					_signed;
		int const				_signGrade;
		int const				_execGrade;

};
std::ostream &operator<<(std::ostream &o, Form const &rhs);
