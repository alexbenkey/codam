#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed (void) : _fixedPointValue(0) {
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed (void){
	//std::cout << "Default destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &rhs){
	//std::cout << "Copy assignment operator overload" << std::endl;
	this->_fixedPointValue = rhs.getRawBits();
	return *this;
}

bool Fixed::operator>(Fixed const &rhs) const{
	return (this->_fixedPointValue > rhs.getRawBits());
}

bool Fixed::operator<(Fixed const &rhs) const{
	return (this->_fixedPointValue < rhs.getRawBits());
}

bool Fixed::operator>=(Fixed const &rhs) const{
	return (this->_fixedPointValue >= rhs.getRawBits());
}

bool Fixed::operator<=(Fixed const &rhs) const{
	return (this->_fixedPointValue <= rhs.getRawBits());
}

bool Fixed::operator==(Fixed const &rhs) const{
	return (this->_fixedPointValue == rhs.getRawBits());
}

bool Fixed::operator!=(Fixed const &rhs) const{
	return (this->toFloat() != rhs.toFloat());
}

Fixed Fixed::operator+(Fixed const &rhs) const{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(Fixed const &rhs) const{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const &rhs)const{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const &rhs)const{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &Fixed::operator++(void){
	this->_fixedPointValue++;
	return (*this);
}

Fixed Fixed::operator++(int){
	Fixed temp(*this);
	operator++();
	return (temp);
}

Fixed &Fixed::operator--(void){
	this->_fixedPointValue--;
	return (*this);
}

Fixed Fixed::operator--(int){
	Fixed temp(*this);
	operator--();
	return (temp);
}

Fixed 	&Fixed::min(Fixed &a, Fixed &b){
	if (a < b)
		return (a);
	return (b);
}

const Fixed 	&Fixed::min(Fixed const &a, Fixed const &b){
	if (a < b)
		return (a);
	return (b);
}

Fixed 	&Fixed::max(Fixed &a, Fixed &b){
	if (a > b)
		return (a);
	return (b);
}

const Fixed 	&Fixed::max(Fixed const &a, Fixed const &b){
	if (a > b)
		return (a);
	return (b);
}

Fixed::Fixed(Fixed const &rhs ) {
    //std::cout << "Copy constructor called" << std::endl;
    this->_fixedPointValue = rhs.getRawBits();
}

Fixed::Fixed(int const rhs ) {
    //std::cout << "int constructor called" << std::endl;
    this->_fixedPointValue = rhs << _fixedPointValueBits;
}

Fixed::Fixed(float const rhs ) {
    //std::cout << "Float constructor called" << std::endl;
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
