#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

class PhoneBook
{
private:
    contact arr[8];
public:
    bool add_contact(int i);
    bool search(int size);
    PhoneBook(){};
    ~PhoneBook(){};
};

#endif