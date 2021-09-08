/*
CH-230-A
a11_p4.cpp
Antonia Savu
asavu@jacobs-university.de
*/
#include <iostream>
#include "Creature.h" //including the header
using namespace std;

Creature::~Creature()
{
    cout << "Calling the destructor\n";
    //added a destructor and its comment
}

Creature::Creature() : distance(10)
{
    cout << "Calling the creature constructor\n";
    //added comments for each constructor
}
Wizard::Wizard() : distFactor(3)
{
    cout << "Calling the wizard constructor\n";
}
Fairy::Fairy() : flying(30)
{
    cout << "Calling the fairy constructor\n";
}
Dragon::Dragon() : fire(15)
{
    cout << "Calling the dragon constructor\n";
}
void Creature::run() const
{
    cout << "running " << distance << " meters!\n";
}

void Fairy::fly() const
{
    cout << "flying " << flying + distance << " meters!\n";
    //defining the methods
}
void Dragon::bfire() const
{ //for both of the new creatures
    cout << "breathing fire over " << (fire * distance) << " meters!\n";
}
void Wizard::hover() const
{
    cout << "hovering " << (distFactor * distance) << " meters!\n";
}
