#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	Cat *j = new Cat();
	Dog *i = new Dog();
	Cat *Deepcopy = new Cat(*j);
	Dog *Deepcopy2 = new Dog(*i);
	Deepcopy->set_idea(5, "I think I am satisfied");
	Deepcopy2->set_idea(5, "I think I am satisfied");

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "address of j: " << &j << std::endl;
	std::cout << "address of j brain: ";
	j->print_brain();
	std::cout << std::endl;
	std::cout << "address of deepcopy: " << &Deepcopy << std::endl;
	std::cout << "address of deepcopy brain: ";
	Deepcopy->print_brain();
	std::cout << std::endl;

	std::cout << "address of i: " << &i << std::endl;
	std::cout << "address of i brain: ";
	i->print_brain();
	std::cout << std::endl;
	std::cout << "address of deepcopy: " << &Deepcopy2 << std::endl;
	std::cout << "address of deepcopy brain: ";
	Deepcopy2->print_brain();
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	Animal *array[20];
	for (int i = 0; i < 20; i++){
		if (i % 2 == 0)
			array[i] = new Cat();
		else
			array[i] = new Dog();
	}

	for (int i = 0; i < 20; i++){
		array[i]->makeSound();
	}

	for (int i = 0; i < 20; i++){
		delete array[i];
	}

	delete Deepcopy;
	delete Deepcopy2;
	delete i;
	delete j;
}