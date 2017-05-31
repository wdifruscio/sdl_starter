#ifndef SHIP 
#define SHIP

#include <string>


using namespace std;

class Ship
{
    public:
        
        //Initializes variables
        Ship( string str );
        
        string setName( string str );
        string getName();

    private:
        string shipName;
};

#endif