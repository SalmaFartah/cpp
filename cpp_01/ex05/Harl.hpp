#include <string>
#include <iostream>

class Harl
{
private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
    std::string table[4];
    void (Harl::*caller[4])( void );
public:
    void complain( std::string level );
    Harl();
    ~Harl(){};
};
