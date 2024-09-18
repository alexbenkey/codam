#include "RPN.hpp"

int main(int argc, char **argv){
	if (argc != 2){
		std::cerr << "invalid input" << std::endl;
		return 0;
	}
	RPN rpn;
	rpn.convertVals(argv[1]);
	rpn.Calc();
}