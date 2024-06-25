#include "Data.hpp"
#include "Serializer.hpp"

int main() {
    Data* Ptr = new Data(66);
    uintptr_t serializedPtr = Serializer::serialize(Ptr);
    Data* deserializedPtr = Serializer::deserialize(serializedPtr);

    if (Ptr != deserializedPtr) {
		std::cout << "something went wrong, address of Ptr: " << Ptr << ", address of deserializedPtr: " << deserializedPtr << std::endl;
    } 
	else {
        std::cout << "Success!" << std::endl;
		std::cout << "Original data: " << Ptr->getData() << std::endl;
		std::cout << "Deserialized data: " << deserializedPtr->getData() << std::endl;
	}

    delete Ptr;
    return 0;
}