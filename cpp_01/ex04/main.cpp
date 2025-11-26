#include "ManFile.hpp"

int main(int ac, char *av[])
{
	if (ac != 4)
		return std::cerr << "bad argument !" << std::endl, 1;

	std::string buffer = ManFile::readfile(av[1]);// read infile
	if (ManFile::infileError())
		return std::cerr << av[1] << ": not exist OR permission denied !\n", 1;

	ManFile::copyReplace(av[1], buffer, av[2], av[3]);
	if (ManFile::outfileError())
		return std::cerr << "outFile: permission denied !\n", 1;
}
