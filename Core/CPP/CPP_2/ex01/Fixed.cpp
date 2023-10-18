#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed (void) : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed (void){
	std::cout << "Default destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &rhs){
	std::cout << "Copy assignment operator overload" << std::endl;
	this->_fixedPointValue = rhs.getRawBits();
	return *this;
}

Fixed::Fixed(Fixed const &rhs ) {
    std::cout << "Copy constructor called" << std::endl;
    this->_fixedPointValue = rhs.getRawBits();
}

Fixed::Fixed(int const rhs ) {
    std::cout << "int constructor called" << std::endl;
    this->_fixedPointValue = rhs << _fixedPointValueBits;
}

Fixed::Fixed(float const rhs ) {
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = (float)std::roundf((rhs * (1 << _fixedPointValueBits)));
}

int Fixed::getRawBits(void) const{
	return(this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw){
	this->_fixedPointValue = raw;
}

float 	Fixed::toFloat( void ) const{
	return ((float)this->getRawBits() / (1 << _fixedPointValueBits));
}

int 	Fixed::toInt( void ) const{
	return this->_fixedPointValue >> _fixedPointValueBits;
}

std::ostream&   operator<<(std::ostream &o, Fixed const &rhs){
	o << rhs.toFloat();
	return (o);
}