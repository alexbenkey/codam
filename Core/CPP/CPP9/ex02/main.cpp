#include "PmergeMe.hpp"

int main(int argc, char **argv){
	if (argc < 2){
		std::cerr << "no input values" << std::endl;
		return 1;
	}
	PmergeMe p;
	std::list<int> start;
	for (int i = 1; i < argc; i++){
		if (std::isdigit(argv[i][0])){
			start.push_back(argv[i][0] - '0');
		}
		else{
			std::cerr << "Error" << std::endl;
			exit (1);
		}
	}
	p.setList(start);
	// for (auto j : start)
	// 	std::cout << j << std::endl;
	p.splitVals();
}