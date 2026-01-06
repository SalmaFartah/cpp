#pragma once
#include <stdint.h>
#include "Data.hpp"
#include <iostream>

class Serializer
{
	Serializer();
	Serializer(const Serializer& old);
	Serializer& operator=(const Serializer& old);

public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
	~Serializer();
};
