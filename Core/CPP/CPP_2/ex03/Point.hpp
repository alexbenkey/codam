#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point 
{
	private:
		Fixed::_fixedPointValue x;
		Fixed::_fixedPointValue y;




	public:
		Point(void);
		~Point(void);

}

bool bsp( Point const a, Point const b, Point const c, Point const point);


#endif