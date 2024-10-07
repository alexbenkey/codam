#pragma once

#include <iostream>
#include <ostream>
#include <list>
#include <vector>
#include <ctime>
#include <string>
#include <stdio.h>
#include <string.h>

class PmergeMe{
	public:
		PmergeMe();
		PmergeMe(PmergeMe & rhs);
		PmergeMe &operator=(PmergeMe & rhs);
		~PmergeMe();

		void				sort_vec(std::vector<int> &vec);
		bool				isSortedVec(std::vector<int> &vec);
		std::vector<int> 	splitValsVec(std::vector<int> &vec);
		std::vector<int> 	&getList(void);

		size_t				findLowValVec(const std::vector<int>& vec, size_t start);
		void				recursiveSortVec(std::vector<int>& vec, size_t start);

		size_t				findLowValList(const std::list<int>& list, size_t start);
		void				recursiveSortList(std::list<int>& list, size_t start);

		int  				listGet(std::list<int> list, int place);
		void  				listSet(std::list<int> & list, int place, int val);

		void				recursiveSortPairsVec(std::vector<int> &vec1, std::vector<int> &vec2, size_t start);
		void				sortPairsVec(std::vector<int> &vec1, std::vector<int> &vec2);
		void				binarySearch(std::list<int> &list, std::vector<int> & vec);

		//void				sortIntoMain(int val, int pos, std::vector<int> &vec1);

};

// std::ostream &operator<<(std::ostream &os, const std::vector<int> &container){
// 	for (std::vector<int>::const_iterator it = container.begin(); it != container.end(); it++)
// 	{
// 		os << *it << " ";
// 	}
// 	return os;
// }

// std::ostream &operator<<(std::ostream &os, const std::list<int> &container){
// 	for (std::list<int>::const_iterator it = container.begin(); it != container.end(); it++)
// 	{
// 		os << *it << " ";
// 	}
// 	return os;
// }