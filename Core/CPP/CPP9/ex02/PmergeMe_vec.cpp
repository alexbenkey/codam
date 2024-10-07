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

size_t PmergeMe::findLowValVec(const std::vector<int>& vec, size_t start) {
    size_t  lowValIndex = start;
    for (size_t  i = start + 1; i < vec.size(); i++) {
        if (vec[i] < vec[lowValIndex]) {
            lowValIndex = i;
        }
    }
    return lowValIndex;
}

void PmergeMe::recursiveSortVec(std::vector<int>& vec, size_t start) {
    if ((size_t)start >= vec.size() - 1) {
        return;
    }
    size_t  minIndex = findLowValVec(vec, start);
    if (minIndex != start) {
        std::swap(vec[start], vec[minIndex]);
    }
    recursiveSortVec(vec, start + 1);
}

std::vector<int> PmergeMe::splitValsVec(std::vector<int> &vec){
	if (vec.empty())
		std::cout << "no vector" << std::endl;
	int len = (vec.size());
	std::vector<int> l;
	for (int i = 0; i < len / 2; i++){
		l.push_back(vec.back());
		vec.pop_back();
	}
	return l;
}

void PmergeMe::recursiveSortPairsVec(std::vector<int> &vec1, std::vector<int> &vec2, size_t start){
    if ((size_t)start >= vec1.size() - 1) {
        return;
    }
    size_t  minIndex = findLowValVec(vec1, start);
    if (minIndex != start) {
        std::swap(vec1[start], vec1[minIndex]);
        std::swap(vec2[start], vec2[minIndex]);
    }
    recursiveSortPairsVec(vec1, vec2, start + 1);
}

void PmergeMe::sortPairsVec(std::vector<int> &vec1, std::vector<int> &vec2){
    size_t temp;
    for (size_t i = 0; i < vec1.size(); i++) {
        if (vec1[i] < vec2[i] && vec2[i]){
            temp = vec1[i];
            vec1[i] = vec2[i];
            vec2[i] = temp;
        }
    }
}

// void PmergeMe::sortIntoMain(int val, int pos, std::vector<int> & vec1){

    
// }   

// void PmergeMe::binarySearch(std::list<int> &list, std::vector<int> &vec){
//     for (int i = 1; i < list.size(); i++){
        
//     }
// }

PmergeMe::~PmergeMe(){};