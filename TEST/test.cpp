#include <iostream>
#include <string>
#include <vector>

class test
{
public:
    test();
    ~test();
};

test::test()
{
    std::cout << "object created\n";
}

test::~test()
{
    std::cout << "object destroyed\n";
}


int main()
{

    test var;

    return 0;
}
