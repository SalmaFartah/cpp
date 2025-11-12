#include <iostream>
#include <fstream>
#include <sstream>

void replace(std::string buffer, std::string s1, std::string s2)
{
    std::string ret;
    size_t start = 0;
    size_t end = 0;

    while (end != std::string::npos && start != buffer.length())
    {
        end = buffer.find(s1, start);
        ret += buffer.substr(start, end - start);
        if (end != std::string::npos)
            ret += s2;
        start = end + s1.length();
    }
    std::ofstream out("outFile");
    out << ret;
}

int main(int ac, char *av[])
{
    if (ac != 4)
        return std::cerr << "bad args !" << std::endl, 1;
    std::ifstream myfile(av[1]);
    if (!myfile.is_open())
        return std::cerr << "file: " << av[1] << " not exist or not permitted !" << std::endl, 1;
    std::stringstream buffer;
    buffer << myfile.rdbuf();
    replace(buffer.str(), av[2], av[3]);
}
