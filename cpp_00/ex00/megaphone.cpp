#include <iostream>

int main(int ac, char **av)
{
	int i;	

	
	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	i = 1;
	while (av[i])
	{
		int j = 0;
		while (av[i][j])
		{
			av[i][j] = std::toupper(av[i][j]);
			j++;
		}
		std::cout << av[i];
		i++;
	}
    std::cout << std::endl;
}
