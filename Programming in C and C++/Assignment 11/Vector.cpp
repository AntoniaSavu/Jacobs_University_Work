/*
CH-230-A
Vector.cpp A11_p6
Muhamad KADI AMEEN
m.kadiameen@jacobs-university.de
*/

#include "Vector.h"
#include <iostream>
#include <cstring>
#include <cmath>

//default constructor
Vector::Vector()
{
    P = NULL;
    size = 0;
}

//constructor with parameter
Vector::Vector(int s)
{
    size = s;
    P = new double[s];
}

//copy constructor
Vector::Vector(const Vector &other)
{
    size = other.size;
    P = new double[size];
    P = other.P;
    //copy raw memory to the destination
}

//destructor
Vector::~Vector()
{
    if (P != NULL)
        delete[] P;
}

double Vector::at(int i) const
{
    return P[i];
} //indexing

void Vector::setAt(int i, double d)
{
    if (i >= size)
        exit(1); // error on size
    P[i] = d;
}

int Vector::length() const
{
    return size;
}
//return the size

void Vector::grow(int i)
{
    double *tmp = P;
    int prev_size = size;
    //previous info
    if (i <= size)
        return;
    //set proper value and grow
    P = new double[i];
    size = i;
    if (prev_size == 0 || tmp == NULL)
        return;
    //make sure the pointers are valid
    memcpy(P, tmp, sizeof(double) * prev_size);
    //copy the content
    delete[] tmp;
    //free the resources
}

//print functions for vectors
void Vector::print() const
{
    if (size == 0)
    {
        std::cout << "[]" << std::endl;
        return;
    }
    std::cout << "[ ";
    for (int i = 0; i < size; i++)
    {
        std::cout << P[i] << " ";
    }
    std::cout << "]" << std::endl;
}

double Vector::norm() const
{
    double sq_sum = 0.0;
    for (int i = 0; i < size; i++)
        sq_sum += P[i];
    return sqrt(sq_sum);
}

Vector Vector::sum(const Vector &other) const
{
    if (size != other.size)
        return Vector();
    Vector rst(size); // create a equal size vector
    for (int i = 0; i < size; i++)
    {
        rst.setAt(i, at(i) + other.at(i));
    } //add the result
    return rst;
}

Vector Vector::diff(const Vector &other) const
{
    if (size != other.size)
        return Vector();
    Vector rst(size); // create a equal size vector
    for (int i = 0; i < size; i++)
    {
        rst.setAt(i, at(i) - other.at(i));
    } //add the result
    return rst;
}

double Vector::scalarP(const Vector &other) const
{
    if (size == 0 || size != other.size)
        return 0;
    double p = 0.0;
    for (int i = 0; i < size; i++)
    {
        p += at(i) * other.at(i);
    }
    return p;
}
