#ifndef ManFile_HPP
#define ManFile_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class ManFile
{
private:
    static bool inErr;
    static bool outErr;
public:
    static std::string readfile(std::string fileName);
    static bool infileError();
    static void copyReplace(std::string filename, std::string fileBuff, std::string s1, std::string s2);
    static bool outfileError();
    ManFile();
    ~ManFile();
};

#endif
