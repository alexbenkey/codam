#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point 
{
	private:
		Fixed const _x;
		Fixed const _y;

	public:
		Point(void);
		~Point(void);
		Point(float const x, float const y);
		Point(Point const &rhs);
		Point &operator=(Point const &rhs);
		//float operator+(float const &rhs) const;
		Fixed const get_x(void) const;
		Fixed const get_y(void) const;
};

std::ostream&   operator<<(std::ostream &o, Point const &rhs);

bool bsp( Point const a, Point const b, Point const c, Point const point);
// float calc_sa(Point const a, Point const b, Point const c);
// float line_length(Point const a, Point const b);

#endif