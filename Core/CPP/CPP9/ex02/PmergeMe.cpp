#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){};
	
PmergeMe::PmergeMe(PmergeMe & rhs){
	*this = rhs;
};

PmergeMe & PmergeMe::operator=(PmergeMe & rhs){
	*this = rhs;
	return (*this); 
};

PmergeMe::~PmergeMe(){};