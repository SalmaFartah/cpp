#pragma once
#include <iostream>

template <typename T, typename retType, typename paramType>
void iter(T array, const int length, retType (*f)(paramType&))
{
    for (int i = 0; i < length; i++)
        f(array[i]);
}
