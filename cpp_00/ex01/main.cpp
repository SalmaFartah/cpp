#include "PhoneBook.hpp"

int main()
{
    int index;
    int contacts;
    PhoneBook mybook;
    std::string line;

    index = 0;
    contacts = 0;
    while (1)
    {
        std::cout << "choose ADD, SEARCH or EXIT> ";
        if (!std::getline(std::cin, line))
            return std::cout << std::endl, 0;
        if (line == "ADD")
        {
            mybook.add_contact(index);
            index++;
            if (contacts < 8)
                contacts++;
        }
        if (line == "EXIT")
            exit(0);
        if (line == "SEARCH")
            mybook.search(contacts);
        if (index == 8)
            index = 0;
    }

}
