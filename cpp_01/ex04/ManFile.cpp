#include "ManFile.hpp"

bool ManFile::inErr = false;
bool ManFile::outErr = false;

std::string ManFile::readfile(std::string fileName)
{
	std::ifstream inf(fileName);
	std::stringstream buffer;
	if (!inf.is_open())
	{
		inErr = true;
		return "";
	}
	inErr = false;
	buffer << inf.rdbuf();
	return buffer.str();
}

bool ManFile::infileError()
{
	return inErr;
}
bool ManFile::outfileError()
{
	return outErr;
}

void ManFile::copyReplace(std::string fileBuff, std::string s1, std::string s2)
{
	std::string replaced;
    size_t start = 0;
    size_t end = 0;

    while (end != std::string::npos && start != fileBuff.length())
    {
        end = fileBuff.find(s1, start);
        replaced += fileBuff.substr(start, end - start);
        if (end != std::string::npos)
            replaced += s2;
        start = end + s1.length();
    }
    std::ofstream out("outFile");
	if (!out.is_open())
	{
		outErr = true;
		return ;
	}
	outErr = false;
    out << replaced;
}