#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed &operator=(Fixed const &rhs);
		bool operator>(Fixed const &rhs) const;
		bool operator<(Fixed const &rhs) const;
		bool operator>=(Fixed const &rhs) const;
		bool operator<=(Fixed const &rhs) const;
		bool operator==(Fixed const &rhs) const;
		bool operator!=(Fixed const &rhs) const;
		Fixed operator+(Fixed const &rhs) const;
		Fixed operator-(Fixed const &rhs) const;
		Fixed operator*(Fixed const &rhs) const;
		Fixed operator/(Fixed const &rhs) const;
		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);
		Fixed(Fixed const &rhs);
		Fixed(int const rhs);
		Fixed(float const rhs);
		~Fixed(void);

		static Fixed 		&min(Fixed &a, Fixed &b);
		static const Fixed 	&min(Fixed const &a, Fixed const &b);
		static Fixed 		&max(Fixed &a, Fixed &b);
		static const Fixed 	&max(Fixed const &a, Fixed const &b);

		int 				getRawBits(void) const;
		void 				setRawBits(int const raw);
		float 				toFloat( void ) const;
		int 				toInt( void ) const;

	private:
		int 				_fixedPointValue;
		static const int 	_fixedPointValueBits = 8;

};
std::ostream&   operator<<(std::ostream &o, Fixed const &rhs);
#endif