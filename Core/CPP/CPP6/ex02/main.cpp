#include "Base.hpp"

int main (void){
	Base *inst = generate();
	identify(inst);
	identify(*inst);
	return 0;
};
