#include "Serializer.hpp"

Serializer::Serializer(){
    // default constructor
}

Serializer::~Serializer(){
    // default destructor
};

Serializer::Serializer(Serializer const &Rhs){
    *this = Rhs;
};

Serializer&  Serializer::operator=(Serializer const &Rhs){
    (void) Rhs;
    return *this;
}; 

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
};

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
};

