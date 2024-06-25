#include "iter.hpp"
#include <vector>
#include <iostream>

template <typename T>
void print_val(const T &a){
	std::cout << a << std::endl;
}

int main(void){
	int i_Array[] = {1, 2, 3, 4, 5};
    size_t a_size = sizeof(i_Array) / sizeof(i_Array[0]);

    std::cout << "array: " << std::endl;
    iter(i_Array, a_size, print_val<int>);
    std::cout << std::endl;

	double d_Array[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t d_size = sizeof(d_Array) / sizeof(d_Array[0]);

    std::cout << "array: " << std::endl;
    iter(d_Array, d_size, print_val<double>);
    std::cout << std::endl;

	char c_Array[] = {'a', 'b', 'c', 'd', 'e'};
    size_t c_size = sizeof(c_Array) / sizeof(c_Array[0]);

    std::cout << "array: " << std::endl;
    iter(c_Array, c_size, print_val<char>);
    std::cout << std::endl;
	
	std::string s_Array[] = {"first", "second", "third", "fourth", "fifth"};
    size_t s_size = sizeof(s_Array) / sizeof(s_Array[0]);

    std::cout << "array: " << std::endl;
    iter(s_Array, s_size, print_val<std::string>);
    std::cout << std::endl;

}
