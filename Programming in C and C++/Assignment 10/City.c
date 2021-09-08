/*
CH-230-A
a10_p3.cpp
Antonia Savu
asavu@jacobs-university.de
*/

#include <iostream>
#include "City.h"

using namespace std;

void City::setName(string &newname)
{
    name = newname;
}
void City::setMayor(string &newmayor)
{
    mayor = newmayor;
}
void City::setInhabitants(int newnum_inhabitants);
{
    num_inhabitants = newnum_inhabitants;
}
void City::setArea(double newarea)
{
    area = newarea;
}

std::string getName()
{
    return name;
}
std::string getMayor()
{
    return name;
}
double getArea()
{
    return area;
}
int getInhabitants()
{
    return num_inhabitants;
}