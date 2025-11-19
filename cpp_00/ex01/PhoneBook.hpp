#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>

class PhoneBook
{
private:
    Contact arr[8];
public:
    bool add_contact(int i);
    bool search(int size);
    PhoneBook();
    ~PhoneBook();
};

#endif