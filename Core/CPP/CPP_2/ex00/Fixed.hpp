#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed &operator=(Fixed const &rhs);
		Fixed(Fixed const &rhs);
		~Fixed(void);

		int 	getRawBits(void) const;
		void 	setRawBits(int const raw);

	private:
		int 				_fixedPointValue;
		static const int 	_fixedPointValueBits = 8;
				
};

#endif