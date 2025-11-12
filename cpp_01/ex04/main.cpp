#include <iostream>
#include <fstream>
#include <sstream>

void replace(std::string buffer, std::string s1, std::string s2)
{

}

int main(int ac, char *av[])
{
    if (ac != 4)
        return std::cerr << "bad args !" << std::endl, 1;
    std::ifstream myfile(av[1]);
    if (!myfile.is_open())
        std::cerr << "error !" << std::endl;
    std::stringstream buffer;
    buffer << myfile.rdbuf();
    std::ofstream out("outfile");
    out << buffer.str();
    // std::cout << buffer.str() << std::endl;
}
