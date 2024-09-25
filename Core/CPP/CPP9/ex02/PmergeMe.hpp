#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <ctime>
#include <string>
#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h> 

class PmergeMe{
	public:
		PmergeMe();
		PmergeMe(PmergeMe & rhs);
		PmergeMe &operator=(PmergeMe & rhs);
		~PmergeMe();

		void				sort_vec(std::vector<int> &vec);
		bool				isSortedVec(std::vector<int> &vec);
		std::vector<int> 	splitVals(std::list<int> &list);
		std::vector<int> 	&getList(void);

		size_t				findLowValVec(const std::vector<int>& vec, size_t start);
		void				recursiveSortVec(std::vector<int>& vec, size_t start);

		size_t				findLowValList(const std::list<int>& list, size_t start);
		void				recursiveSortList(std::list<int>& list, size_t start);

		int  				listGet(std::list<int> list, int place);
		void  				listSet(std::list<int> & list, int place, int val);


};