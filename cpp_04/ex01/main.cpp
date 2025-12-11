#include "Cat.hpp"
#include "Dog.hpp"
#include <unistd.h>


int main()
{
	std::string GREEN  = "\033[32m";
	std::string ORANGE = "\033[38;5;208m";
	std::string RESET  = "\033[0m";
	std::cout << GREEN << "\n--- SINGLE OBJECT DELETION ---\n" << RESET;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << ORANGE << "\n🔥 Deleting Dog 🦮 through Animal pointer...\n" << RESET;
		delete j;//should not create a leak
		std::cout << ORANGE << "\n🔥 Deleting Cat 🐈 through Animal pointer...\n" << RESET;
		delete i;
	}

	std::cout << GREEN << "\n--- ARRAY OF OBJECTS DELETION ---\n" << RESET;
	{
	   Animal *anim[20];
	   for (int i = 0; i < 20; i++)
	   {
			if (i < 10)
				anim[i] = new Dog;
			else
				anim[i] = new Cat;
	   }
	   std::cout << ORANGE << "\n🎉 Herd of 20 animals created! 10 dogs, 10 cats\n" << RESET;
	   for (int b = 0; b < 20; b++)
	   {
			std::cout << ORANGE << "💥 Deleting animal #" << (b+1) << ": 👇" << std::endl << RESET;
			delete anim[b];	   
	   }
	}
	std::cout << GREEN << "\n🕊️ ALL ANIMALS DELETED..\n" << RESET;
	// system("leaks -q exec");
	return 0;
}
