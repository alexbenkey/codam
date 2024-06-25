#include "Base.hpp"

Base *generate(void){
	unsigned seed = time(0);
	srand(seed);
	int V1 = (rand() % 3) + 1;
	Base *baseptr = nullptr; 
	if (V1 == 1)
		baseptr = new A;
	else if (V1 == 2)
		baseptr = new B;
	else if (V1 == 3)
		baseptr = new C;
	return (baseptr);
};

void identify(Base* p){
	if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "not a know class" << std::endl;
};

void identify(Base& p){
	try {
		A &a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void) a;
	} catch(const std::exception &e) {};
	try {
		B &b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void) b;
	} catch(const std::exception &e) {};
	try {
		C &c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void) c;
	} catch(const std::exception &e) {};
};
