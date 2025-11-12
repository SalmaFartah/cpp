#include <iostream>
#include <fstream>
#include <sstream>

void replace(std::string buffer, std::string s1, std::string s2)
{
	int pos = 0;
	for (int i = 0; i < buffer.length(); i++)
	{
		pos = buffer.find(s1, pos);
		std::cout << pos << std::endl;
	}
	
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
	replace(buffer.str(), av[2], av[3]);
	// std::ofstream out("outfile");
	// out << buffer.str();
	// std::cout << buffer.str() << std::endl;
}
