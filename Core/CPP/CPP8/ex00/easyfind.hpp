#include <iostream>
#include <vector>

template <typename T>
int easyfind(const T &cont, int i){
	for (auto v : cont){
		if (v == i)
			return (v);
	}
	return (-1);
}
