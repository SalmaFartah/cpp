#include "HumanA.hpp"


HumanA::HumanA(std::string newName, Weapon& newWeap) : myWeap(newWeap){		name = newName;		}

HumanA::~HumanA(){}

void HumanA::attack(){		std::cout << name << " attacks with their " << myWeap.getType() << std::endl;		}
