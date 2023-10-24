#include "Point.hpp"

#include <cmath>
#include <iostream>


Fixed static abs(Fixed const val)
{
	if (val < 0)
		return (val * -1);
	else
		return (val);
}

static Fixed calc_sa(Point const a, Point const b, Point const c)
{
	return (abs((( a.get_x() * ( b.get_y() - c.get_y() )) + 
			  (b.get_x() * (c.get_y() - a.get_y())) + 
			  (c.get_x() * (a.get_y() - b.get_y()))) / 2));
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
	if (((calc_sa(a, b, point) + calc_sa(a, c, point) + calc_sa(b, c, point)) == calc_sa(a, b, c)) && \
		(calc_sa(a, b, point) != 0) && (calc_sa(a, c, point) != 0)&&  (calc_sa(b, c, point) != 0))
	{	
		std::cout << "point is inside the triangle" << std::endl;
		// if (calc_sa(a, b, point) == 0)
		// 	std::cout << " a, b, point = 0" <<std::endl;
		// if (calc_sa(a, c, point) == 0)
		// 	std::cout << " a, c, point = 0" <<std::endl;
		// if (calc_sa(b, c, point) == 0)
		// 	std::cout << " b, c, point = 0" <<std::endl;
		return (1);
	}
	else
	{
		std::cout << "point is not inside the triangle" << std::endl;
		return (0);
	}
	return (1);
}
