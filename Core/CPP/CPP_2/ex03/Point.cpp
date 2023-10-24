#include "Point.hpp"
#include <iostream>

Point::Point(void): _x(0), _y(0) {
	//std::cout << "Point has been constructed" << std::endl;
}

Point::~Point(void) {
	//std::cout << "Point has been destructed" << std::endl;
}

Point::Point(float const x, float const y): _x(x), _y(y) {
    //std::cout << "int constructor called" << std::endl;
}

Point::Point(Point const &rhs): _x(rhs._x), _y(rhs._y){
	*this = rhs;
}

Point &Point::operator=(Point const &rhs){
	return *this;
}

Fixed const Point::get_x() const{
	return (this->_x);
}

Fixed const Point::get_y() const{
	return (this->_y);
}

std::ostream&   operator<<(std::ostream &o, Point const &rhs){
	o << rhs.get_x().toFloat() << ',' << rhs.get_y().toFloat();
	return (o);
}