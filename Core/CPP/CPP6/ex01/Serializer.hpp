#pragma once

#include <iostream>
#include "Data.hpp"

class Serializer {
private:
    Serializer();
    ~Serializer();
	Serializer(Serializer const &Rhs);
	Serializer& operator=(Serializer const &Rhs); 

public:
   static uintptr_t serialize(Data *ptr);
   static Data * deserialize(uintptr_t raw);

};