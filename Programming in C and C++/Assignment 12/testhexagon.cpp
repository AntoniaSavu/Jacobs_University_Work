/*
CH-230-A
a12_p1.h
Antonia Savu
asavu@jacobs-university.de
*/
#include <iostream>
#include "Shapes.h"
using namespace std;
int main()
{

    Hexagon h1("h1", 1, 2, 6, 9, "blue");
    //declaring using parameter constructor
    Hexagon h2("h2", 3, 4, 6, 15, "green");
    //declaring using parameter constructor
    Hexagon h3(h2);
    //declaring using copy constructor

    cout << "Perimeter and Area of the " << h1.getColor() << " hexagon.(first):\n";
    cout << h1.perimeter() << "    " << h1.area();
    cout << "\n\nPerimeter and Area of the " << h2.getColor() << " hexagon.(second):\n";
    cout << h2.perimeter() << "    " << h2.area();
    cout << "\n\nPerimeter and Area of the " << h3.getColor() << " hexagon.(third):\n";
    cout << h3.perimeter() << "    " << h3.area() << "\n";

    return 0;
}
