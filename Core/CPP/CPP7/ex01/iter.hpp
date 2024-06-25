#pragma once
#include <cstdlib>

template <typename T, typename Func>
void iter(const T *a, const size_t len, Func Function){
	for(size_t i = 0; i < len; ++i)
		Function(a[i]);
};

