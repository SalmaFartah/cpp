#pragma once
#include <algorithm>
#include <iostream>

template <typename T>
int easyfind(T container, int nb)
{
	typename T::iterator ret = std::find(container.begin(), container.end(), nb);
	if (ret == container.end())
		throw std::logic_error("❌ value not found !");
	return std::distance(container.begin(), ret);
}
