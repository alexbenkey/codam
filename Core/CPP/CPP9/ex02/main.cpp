#include "PmergeMe.hpp"

int ft_strcmp(char * s1, char * s2){
	while (*s2 && *s1 && *s2 == *s1)
	{
		s1++;
		s2++;
	}
	return (*s2 - *s1);
}

int main(int argc, char **argv){

	std::list<int> 			list;
	std::vector<int> 		vec;

	// double				listTime;
	// double				dequeTime;


	// listTime = 0;
	// dequeTime = 0;

	if (argc < 2){
		std::cerr << "no input values" << std::endl;
		return 1;
	}
	PmergeMe p;
	for (int i = 1; i < argc; i++){
		for ( size_t j = 0; j < strlen(argv[i]); j++){
			if (!std::isdigit(j + '0')){
				std::cout << "non positive digit detected" << std::endl;
				exit (1);
			}
		}
		list.push_back(std::stoi(argv[i]));
	}
	vec = p.splitVals(list);
	std::cout << "vector: " << std::endl;
	for (auto i : vec)
	std::cout << i << std::endl;
	std::cout << "list: " << std::endl;
	for (auto j : list)
	std::cout << j << std::endl;
	p.sortpairs(list, vec);
	p.recursiveSortPairs(list, vec, 0);
	vec.insert(vec.begin(), p.listGet(list, 0));
	p.binaryAdd(list, vec);

	//list.insert(vec[0]);
	std::cout << "vector: " << std::endl;
	for (auto i : vec)
		std::cout << i << std::endl;
	std::cout << "list: " << std::endl;
	for (auto j : list)
		std::cout << j << std::endl;
}
