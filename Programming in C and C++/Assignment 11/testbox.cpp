/*
CH-230-A
a11_p1.cpp
Antonia Savu
asavu@jacobs-university.de
*/
#include <iostream>
#include <cstdlib>
#include "Box.h"

using namespace std;

int main(int argc, char **argv)
{
    int i, n;
    double height, width, depth;
    cin >> n; //reading the number of boxes
    Box *a;
    a = new Box[2 * n]; //allocating memory
    for (i = 0; i < n; i++)
    {
        cin >> height >> width >> depth;
        //reading the properties for every box
        a[i].setHeight(height); //and setting them
        a[i].setWidth(width);
        a[i].setDepth(depth);
    }
    for (i = n; i < n * 2; i++)
    {
        a[i] = Box(a[i - n]);
        //calling the copy constructor
    }
    for (i = 0; i < 2 * n; i++)
    {
        cout << "Volume is " << a[i].getVolume() << ".\n";
        //printing every volume
    }

    delete[] a; //freeing the memory
    return 0;
}
