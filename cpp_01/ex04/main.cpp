#include "ManFile.hpp"

int main(int ac, char *av[])
{
	if (ac != 4)
		return std::cerr << "bad argument !" << std::endl, 1;

	std::string buffer = ManFile::readfile(av[1]);
	if (ManFile::infileError())
		return std::cerr << av[1] << ": not exist, or his permission is denied !\n", 1;

	ManFile::copyReplace(buffer, av[2], av[3]);
	if (ManFile::outfileError())
		return std::cerr << "outFile: permission denied !\n", 1;	
}
