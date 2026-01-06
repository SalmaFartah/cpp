#include "Serializer.hpp"

int main()
{
    Data *ptr = new Data;
    ptr->k = 98;
    uintptr_t raw = Serializer::serialize(ptr);
    Data *u = Serializer::deserialize(raw);
    std::cout << u->k << std::endl;
    delete ptr;
}
