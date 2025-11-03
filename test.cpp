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

    std::vector<int> vec;
    vec.begin();
    vec.end();

    return 0;
}
