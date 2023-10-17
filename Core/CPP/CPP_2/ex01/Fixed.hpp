#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed &operator=(Fixed const &rhs);
		Fixed(Fixed const &rhs);
		Fixed(int const rhs);
		Fixed(float const rhs);
		~Fixed(void);

		int 	getRawBits(void) const;
		void 	setRawBits(int const raw);
		float 	toFloat( void ) const;
		int 	toInt( void ) const;

	private:
		int 				_fixedPointValue;
		static const int 	_fixedPointValueBits = 8;

};
std::ostream&   operator<<(std::ostream &o, Fixed const &rhs);
#endif