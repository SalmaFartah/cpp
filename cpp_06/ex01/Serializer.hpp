#pragma once
#include <stdint.h>
#include "Data.hpp"
#include <iostream>

class Serializer
{
	Serializer();
public:
	Serializer(const Serializer& old);
	Serializer& operator=(const Serializer& old);
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
	~Serializer();
};
