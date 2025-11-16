#include "Contact.hpp"

Contact::Contact(){}//constructor
Contact::~Contact(){}//destructor

/*-----------------DEFINE-GETTER----------------*/
std::string Contact::get_first_name() const
{
    return first_name;
}

std::string Contact::get_last_name() const
{
    return last_name;
}

std::string Contact::get_nickname() const
{
    return nickname;
}

std::string Contact::get_phone_number() const
{
    return phone_number;
}

std::string Contact::get_darkest_secret() const
{
    return darkest_secret;
}


/*-----------------DEFINE-SETTER----------------*/
void Contact::set_first_name(std::string value)
{
    first_name = value;
}

void Contact::set_last_name(std::string value)
{
    last_name = value;
}

void Contact::set_nickname(std::string value)
{
    nickname = value;
}

void Contact::set_phone_number(std::string value)
{
    phone_number = value;
}

void Contact::set_darkest_secret(std::string value)
{
    darkest_secret = value;
}
