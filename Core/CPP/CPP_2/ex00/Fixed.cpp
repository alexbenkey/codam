#include "Fixed.hpp"

Fixed::Fixed (void){
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
}

Fixed::~Fixed (void){
	std::cout << "Default destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &rhs){
	std::cout << "Copy assignment operator overload called" << std::endl;
	this->_fixedPointValue = rhs.getRawBits();
	return *this;
}

Fixed::Fixed(Fixed const &rhs ) {
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(rhs.getRawBits());
}

Fixed::Fixed(int const &rhs ) {
    std::cout << "int constructor called" << std::endl;
    this->setRawBits(rhs.getRawBits());
}

Fixed::Fixed(float const &rhs ) {
    std::cout << "Float constructor called" << std::endl;
    //this->setRawBits(rhs.getRawBits());
}

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw){
	this->_fixedPointValue = raw;
}

float 	Fixed::toFloat( void ) const{
	//return (this->getRawBits)
	int devision = 1;
	for (int i = 0;i < this->_fixedPointValueBits; i++)
		devision * 0.1;
	return ((float)_fixedPointValue / devision);
}

int 	Fixed::toInt( void ) const{
	return _fixedPointValue >> _fixedPointValueBits;
}

std::ostream&   operator<<(std::ostream &o, Fixed const &rhs){
	o << rhs.toFloat();
}