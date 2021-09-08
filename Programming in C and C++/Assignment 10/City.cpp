/*
CH-230-A
a10_p3.cpp
Antonia Savu
asavu@jacobs-university.de
*/

#include <iostream>
#include "City.h" //including the header file

using namespace std;

void City::setName(string &newname)
{
    name = newname;
    //defining all the setter functions from the class
}
void City::setMayor(string &newmayor)
{
    mayor = newmayor;
}
void City::setArea(double newarea)
{
    area = newarea;
}
void City::setInhabitants(int newnum_inhabitants)
{
    num_inhabitants = newnum_inhabitants;
}
std::string City::getName()
{
    return name;
    //defining all the getter functions from the class
}
std::string City::getMayor()
{
    return name;
}
double City::getArea()
{
    return area;
}
int City::getInhabitants()
{
    return num_inhabitants;
}

void City::print()
{
    cout << "The city of " << name << " has the following characteristics: \n";
    cout << "Number of inhabitants: " << num_inhabitants << "\n";
    cout << "Mayor: " << mayor << "\n";
    cout << "Area: " << area << " km^2\n";
    //the printing function that showcases all the properties
}