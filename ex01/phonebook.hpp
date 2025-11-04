#include "contact.hpp"
#include <iostream>

class PhoneBook
{
public:
    contact arr[8];
public:
    void add_contact(int i);
    void search(int size);
    PhoneBook(){};
    ~PhoneBook(){};
};
