#pragma once

#include <iostream>
#include <list>
#include <vector>

class PmergeMe{
	public:
		PmergeMe();
		PmergeMe(PmergeMe & rhs);
		PmergeMe &operator=(PmergeMe & rhs);
		~PmergeMe();

		void splitVals();
		void setVec(std::vector<int> &in);
		void setList(std::list<int> &in);

	private:

		std::vector<int> vec;
		std::list<int> list;

};