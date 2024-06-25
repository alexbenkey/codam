#pragma once

#include <cstdlib>
#include <typeinfo>
#include <iostream>
#include <ctime>

class Base { 
	public: 
		virtual ~Base() {} 
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

void identify(Base& p);
void identify(Base* p);
Base *generate(void);