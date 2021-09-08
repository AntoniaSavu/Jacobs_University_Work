/*
CH-230-A
a13_p2.cpp
Antonia Savu
asavu@jacobs-university.de
*/

#include <iostream>
#include "Complex.h"

using namespace std;

void Complex::setIm(float newIm)
{ //defining the setters
    im = newIm;
}
void Complex::setReal(float newReal)
{
    real = newReal;
}
float Complex::getIm()
{ //defining the getters
    return im;
}
float Complex::getReal()
{
    return real;
}

Complex::Complex()
{ //the empty constructor
    real = 0;
    im = 0;
    cout << "Calling the first constructor\n";
}
Complex::Complex(float x, float y)
{ //defining the constructor with parameters
    real = x;
    im = y;
    cout << "Calling the second constructor\n";
}
Complex::Complex(const Complex &z)
{ //defining the copy constructor
    im = z.im;
    real = z.real;
    cout << "Calling the copy constructor\n";
}
Complex Complex::add(Complex &z)
{ //defining the addition method
    Complex z1;
    float realz1, imz1;
    realz1 = real + z.getReal();
    imz1 = im + z.getIm();
    z1.setReal(realz1);
    z1.setIm(imz1);
    return z1;
}

Complex Complex::subtract(Complex &z)
{ //defining the subtraction method
    Complex z1;
    float realz1, imz1;
    realz1 = real - z.getReal();
    imz1 = im - z.getIm();
    z1.setReal(realz1);
    z1.setIm(imz1);
    return z1;
}
Complex Complex::multiply(Complex &z)
{ //defining the multiplication method
    Complex z1;
    float realz1, imz1;
    realz1 = real * z.getReal() - im * z.getIm();
    imz1 = real * z.getIm() + im * z.getReal();
    z1.setReal(realz1);
    z1.setIm(imz1);
    return z1;
}
void Complex::print()
{ //printing the number
    if (im)
    {
        cout << noshowpos << real << showpos << im << "i" << endl;
    }
    else
    {
        cout << noshowpos << real << showpos << endl;
    }
}

Complex::~Complex()
{ //defining the destructor
    cout << "Calling the destructor\n";
}
std::istream &operator>>(std::istream &in, Complex &z)
{ //definition for the >> overload
    char i, sign;
    in >> z.real >> sign >> z.im >> i;
    if (sign == '-')
    {
        z.im = -z.im;
    }
    return in;
}

std::ostream &operator<<(std::ostream &os, Complex &z)
{ //definition for the << overload

    if (z.im)
    {
        os << noshowpos << z.real;
        if (z.im != -1 && z.im != 1)
        {
            if (z.im > 0)
                os << '+' << z.im << "i" << endl;
            else
                os << z.im << "i" << endl;
        }
        else
        {
            if (z.im > 0)
                os << '+' << "i" << endl;
            else
                os << '-' << "i" << endl;
        }
    }
    else
    {
        os << noshowpos << z.real << showpos << endl;
    }
    return os;
}

Complex Complex::operator+(Complex z)
{ //overloading the + operator so that it adds Complex numbers
    Complex addition(this->real + z.real,
                     this->im + z.im);
    return addition;
}
Complex Complex::operator-(Complex z)
{ //overloading the - operator so that it subtracts Complex numbers
    Complex substraction(this->real - z.real,
                         this->im - z.im);
    return substraction;
}
void Complex ::operator=(Complex z)
{ //overloading the equal operator so that it
    //assigns a Complex number to another
    this->real = z.real;
    this->im = z.im;
}
Complex Complex::operator*(Complex z)
{ //overloading the * operator so that it multiples Complex numbers
    Complex multiplication(this->real * z.real - this->im * z.im,
                           this->im * z.real + this->real * z.im);
    return multiplication;
}