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

	std::vector<int> 		vec1;
	std::vector<int> 		vec2;
	int 					extraval = 0;		

	// double				listTime;
	// double				dequeTime;


	// listTime = 0;
	// dequeTime = 0;

	if (argc < 2){
		std::cerr << "no input values" << std::endl;
		return 1;
	}
	PmergeMe p;
	//check odd, if odd add to extraval
	for (int i = 1; i < argc; i++){
		for ( size_t j = 0; j < strlen(argv[i]); j++){
			if (!std::isdigit(j + '0')){
				std::cout << "non positive digit detected" << std::endl;
				exit (1);
			}
		}
		vec1.push_back(std::stoi(argv[i]));
	}
	if(vec1.size() % 2 != 0){
		//std::cout << "uneven" << std::endl;
		extraval = vec1[vec1.size() - 1];
		vec1.pop_back();
	}
	else
		(void)extraval;
	// else
	// 	std::cout << "even" << std::endl;
	vec2 = p.splitValsVec(vec1);
	p.sortPairsVec(vec1, vec2);
	p.recursiveSortPairsVec(vec1, vec2, 0); // make sure that there is no issue when odd numbers 
	vec1.insert(vec1.begin(), vec2[0]);
	vec2.erase(vec2.begin());
	int pos = 0;
	for (auto v : vec2) {
		pos++;
		p.sortIntoMain(v, pos, vec1);
	}
	p.binaryAdd(list, vec);

	//vec1.insert(vec[0]);
	// std::cout << "vec1: " << &vec1 << std::endl;
	// std::cout << "vec2: " << &vec2 << std::endl;
	std::cout << "extraval: " << extraval << std::endl; 

	std::cout << "vec1: " << std::endl;
	for (auto i : vec1)
	std::cout << i << std::endl;
	std::cout << "vec2: " << std::endl;
	for (auto j : vec2)
	std::cout << j << std::endl;
}

