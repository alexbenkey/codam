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

size_t PmergeMe::findLowValList(const std::list<int>& list, size_t start) {
    size_t  lowValIndex = start;
    for (size_t  i = start + 1; i < list.size(); i++) {
        if (listGet(list, i) < listGet(list, lowValIndex)) {
            lowValIndex = i;
        }
    }
    return lowValIndex;
}

void  PmergeMe::listSet(std::list<int> & list, int place, int val){
    std::list<int>::iterator it = list.begin();
    for(int i=0; i < place; i++){
        ++it;
    }
    std::cout << "it before: " << *it << std::endl;
    *it = val;
    std::cout << "it after: " << *it << std::endl;
}

int  PmergeMe::listGet(std::list<int> list, int place){
    std::list<int>::iterator it = list.begin();
    for(int i=0; i < place; i++){
        ++it;
    }
    return *it;
}

void PmergeMe::recursiveSortList(std::list<int>& list, size_t start) {
    int temp1;
    int temp2;
    if ((size_t)start >= list.size() - 1) {
        return;
    }
    size_t  minIndex = findLowValList(list, start);
    if (minIndex != start) {
        temp1 = listGet(list, start);
        temp2 = listGet(list, minIndex);
        listSet(list, start, temp2);
        listSet(list, minIndex, temp1);
    }
    recursiveSortList(list, start + 1);
}

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

std::vector<int> PmergeMe::splitVals(std::list<int> &list){
	if (list.empty())
		std::cout << "no list" << std::endl;
	int len = ((list).size());
	std::vector<int> l;
	for (int i = 0; i < len / 2; i++){
		l.push_back(list.back());
		list.pop_back();
	}
	return l;
}

PmergeMe::~PmergeMe(){};