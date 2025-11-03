#include "contact.hpp"
#include <iostream>

class phonebook
{
public:
    contact arr[8];
public:
    void add_contact(int i);
    void search(int size);
    phonebook(){};
    ~phonebook(){};
};
