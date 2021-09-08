/*
CH-230-A
testvector.cpp A11_p6
Muhamad KADI AMEEN
m.kadiameen@jacobs-university.de
*/

#include "Vector.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    Vector v1;
    v1.grow(5); //grow to 5 dimension
    v1.setAt(0, 1.0);
    v1.setAt(1, 2.3);
    v1.setAt(2, 6.7);
    v1.setAt(3, -1.2);
    v1.setAt(4, -2.3);
    cout << "v1: ";
    v1.print();
    //build the first vector

    Vector v2(v1); //copy the first vector
    cout << "v2: ";
    v2.print();

    Vector v3(5);
    v3.setAt(0, 2.4);
    v3.setAt(1, 6.7);
    v3.setAt(2, -9.1);
    v3.setAt(3, 0.6);
    v3.setAt(4, 13);
    cout << "v3: ";
    v3.print();
    //build the second vector
    cout << "Norm of v1: " << v1.norm() << endl;
    cout << "Scalar Product of v1 v3: " << v1.scalarP(v3) << endl;
    //scalar results

    //print the sum and difference
    cout << "the sum: ";
    v1.sum(v3).print();
    cout << "the difference: ";
    v1.diff(v3).print();

    return 0;
}
