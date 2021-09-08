/*
CH-230-A
a11_p3.cpp
Antonia Savu
asavu@jacobs-university.de
*/
#include <iostream>
#include "Creature.h" //including the header
using namespace std;

int main()
{
    cout << "Creating an Creature.\n";
    Creature c; //creating an instance of a creature
    c.run();    //

    cout << "\nCreating a Wizard.\n";
    Wizard w;  //creating an instance of a wizard
    w.run();   //calling the fly function specific to a creature
    w.hover(); //calling the hover function specific to a wizard

    cout << "\nCreating a Fairy.\n";
    Fairy f; //creating an instance of a fairy
    f.run(); //calling the run method specific to a creature
    f.fly(); //calling the fly function specific to a fairy

    cout << "\nCreating a Dragon.\n";
    Dragon d;  //creating an instance of a dragon
    d.run();   //calling the run method specific to a creature
    d.bfire(); //calling the breathing fire function specific to a dragon
    cout << "\n";
    return 0;
}