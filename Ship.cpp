#include "Ship.h"
#include<iostream>
#include<stdio.h>


Ship::Ship( string str ){
    cout << "Object is being created" << endl;
    shipName = str;
};

void Ship::setName( string str)
{
    shipName = str;
}

string Ship::getName()
{
    return shipName;
} 
