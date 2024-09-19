#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){};
	
PmergeMe::PmergeMe(PmergeMe & rhs){
	*this = rhs;
};

PmergeMe & PmergeMe::operator=(PmergeMe & rhs){
	if (this != &rhs)
		return (*this);
	return rhs;
};

void PmergeMe::setVec(std::vector<int> &in){
	vec = in;
}

void PmergeMe::setList(std::list<int> &in){
	list = in;
}

void PmergeMe::splitVals(void){
	int len = ((vec).size() + 1);
	std::vector<int> l;
	for (int i = 0; i < len / 2; i++){
		l.push_back(vec[len - i]);
		vec.pop_back();
	}
	for (auto j : l)
		std::cout << j << std::endl;
}

PmergeMe::~PmergeMe(){};