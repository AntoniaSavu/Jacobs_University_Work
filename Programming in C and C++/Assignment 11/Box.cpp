/*
CH-230-A
a11_p1.cpp
Antonia Savu
asavu@jacobs-university.de
*/

#include <iostream>
#include "Box.h"

using namespace std;

void Box::setDepth(double newdepth)
{ //defining the setters
    depth = newdepth;
}

void Box::setHeight(double newheight)
{
    height = newheight;
}
void Box::setWidth(double newwidth)
{
    width = newwidth;
}

double Box::getDepth()
{ //defining the getters
    return depth;
}
double Box::getWidth()
{
    return width;
}
double Box::getHeight()
{
    return height;
}
double Box::getVolume()
{ //computing the volume
    return height * depth * width;
}
Box::Box()
{ //the first constructor with no parameters
    cout << "The first constructor is called\n";
    width = 0;
    depth = 0;
    height = 0;
}
Box::Box(double a, double b, double c)
{
    cout << "The second constructor is called\n";
    width = b;
    depth = c;
    height = a;
}
Box::Box(const Box &z)
{
    cout << "The copy constructor is called\n";
    width = z.width;
    depth = z.depth;
    height = z.height;
}

Box::~Box()
{
    cout << "The  destructor is called\n";
}
