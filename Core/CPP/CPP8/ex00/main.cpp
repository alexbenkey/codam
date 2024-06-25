#include "easyfind.hpp"

int main (void){
	std::vector<int>cont[20];
	for (int i = 0; i < 20; i++)
		cont->push_back(i);
	if(easyfind(cont, 13) != -1)
		std::cout << "found" << std::endl;
	else
		std::cout << "not found" << std::endl; 
}