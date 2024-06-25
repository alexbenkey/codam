#include "Data.hpp"

Data::Data() {	
};

Data::Data(int value): Data(){
	this->_data = value;
};

Data::~Data(){
};

Data::Data(Data const &Rhs){
	*this = Rhs;
};

Data& Data::operator=(Data const &Rhs){
	this->_data = Rhs._data;
	return *this;
};

int Data::getData() const{
    return _data;
};