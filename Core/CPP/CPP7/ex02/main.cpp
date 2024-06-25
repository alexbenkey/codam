#include <iostream>
#include "Array.hpp"


int main(void){

	// std::cout << "-----------------------------------------------------" << std::endl;

    // Array< float > test;

    // Array< int > intArray( SIZE );
    // Array< int > intArray2( SIZE - 5 );

    // for ( unsigned int i = 0; i < intArray.size(); i++ )
    //     intArray[i] = i * 2;

    // std::cout << "Int Array 1: " << intArray << std::endl;
	// std::cout << "Int Array 2: " << intArray2 << std::endl;

    // intArray2 = intArray;

    // std::cout << "int Array 2: " << intArray2 << std::endl;

    // try {
    //     std::cout << "Accessing a valid index: " << intArray[5] << std::endl;
    //     std::cout << "Accessing an valid index: " << intArray[SIZE - 1] << std::endl;
	// 	std::cout << "Accessing an invalid index: " << intArray[SIZE] << std::endl;
    // } catch ( Array< int >::OutOfBoundsException& e ) {
    //     std::cout << "Error: " << e.what() << std::endl;
    // }

    // std::cout << "-----------------------------------------------------" << std::endl;

    // return ( 0 );
	Array<unsigned int> array1(50);
	for (int i = 0; i < 50; i++){
		array1[i] = i;
	}


	Array<unsigned int> array2(500);
	for (int i (0); i < 500; i++){
		array2[i] = i * 2;
	}
	std::cout << std::endl;

	std::cout << array1.size();
	std::cout << array2.size() << std::endl;

	std::cout << "vals of array 1: " << std::endl;
	std::cout << array1 << std::endl << std::endl;
	std::cout << "vals of array 2: " << std::endl;
	std::cout << array2 << std::endl << std::endl;;
	std::cout << "array2 = array 1" << std::endl;
	array2 = array1;
	std::cout << std::endl << std::endl;;
	std::cout << "vals of array 1: " << std::endl;
	std::cout << array1 << std::endl<< std::endl;
	std::cout << "vals of array 2: " << std::endl;
	std::cout << array2 << std::endl << std::endl;

	std::cout << "trying to access specific values" << std::endl;
	int vals[5] = {45, 49, 50, 145, -1};
	for (auto i: vals){
		try{
			std::cout << "array1[: " << i << "]" << array1[i] << std::endl; }
		catch ( Array<unsigned int>::OutOfBoundsException& e ) {
			std::cout << "Error: " << e.what() << std::endl; }
	}
};