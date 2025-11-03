#include "contact.hpp"

/*-----------------DEFINE-GETTER----------------*/
std::string contact::get_first_name() const
{
    return first_name;
}

std::string contact::get_last_name() const
{
    return last_name;
}

std::string contact::get_nickname() const
{
    return nickname;
}

std::string contact::get_phone_number() const
{
    return phone_number;
}

std::string contact::get_darkest_secret() const
{
    return darkest_secret;
}


/*-----------------DEFINE-SETTER----------------*/
void contact::set_first_name(std::string value)
{
    if (!value.empty())
        first_name = value;
}

void contact::set_last_name(std::string value)
{
    if (!value.empty())
        last_name = value;
}

void contact::set_nickname(std::string value)
{
    if (!value.empty())
        nickname = value;
}

void contact::set_phone_number(std::string value)
{
    if (!value.empty())
        phone_number = value;
}

void contact::set_darkest_secret(std::string value)
{
    if (!value.empty())
        darkest_secret = value;
}
