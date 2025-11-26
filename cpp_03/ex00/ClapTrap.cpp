#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default constructor called !" << std::endl;
    hit_points = 10;
    energy_points = 10;
    attack_damage = 10;
}

ClapTrap::ClapTrap(const ClapTrap& old)
{
    std::cout << "ClapTrap " << name << " is constructed!" << std::endl;
    this->name = old.name;
    this->hit_points = old.hit_points;
    this->energy_points = old.energy_points;
    this->attack_damage = old.attack_damage;
}

const ClapTrap& ClapTrap::operator=(const ClapTrap &old)
{
    this->name = old.name;
    this->hit_points = old.hit_points;
    this->energy_points = old.energy_points;
    this->attack_damage = old.attack_damage;
    return *this;
}

ClapTrap::ClapTrap(std::string newName)
{
    name = newName;
    hit_points = 10;
    energy_points = 10;
    attack_damage = 0;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " is now gone.." << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (energy_points && hit_points)
    {
        energy_points--;
        std::cout << "ClapTrap " << name << " attacks " << target << " , causing " << attack_damage << " points of damage!" << std::endl;
    }
    else if (!energy_points)
        std::cout << "ClapTrap " << name << " cannot attack, no energy left!" << std::endl;
    else
        std::cout << "ClapTrap" << name << " cannot attack, already dead!" << std::endl;
            
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energy_points && hit_points)
    {
        energy_points--;
        hit_points += amount;
        std::cout << "ClapTrap " << name << " repairs itself, gaining " << amount << " hit points!" << std::endl;
    }
    else if (!energy_points)
        std::cout << "ClapTrap " << name << " cannot repair, no energy left!" << std::endl;
    else
        std::cout<< "ClapTrap " << name << " cannot repair, already dead!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (energy_points && hit_points && hit_points > amount)
    {
        hit_points -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage and is knocked out!" << std::endl;
}