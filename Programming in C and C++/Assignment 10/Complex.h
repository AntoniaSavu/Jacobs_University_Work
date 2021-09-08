/*
CH-230-A
a13_p2.h
Antonia Savu
asavu@jacobs-university.de
*/
#include <string> // defines standard C++ string class

/* First C++ class */
class Complex
{
private: // data members are private
    float real;
    float im;

public:                          // business logic methods are public
    void setReal(float newReal); //the prototypes for the setters
    void setIm(float newIm);
    float getReal(); //the prototypes for the getters
    float getIm();
    void print();
    void printConjugate();
    Complex();             //the first constructor, no parameters
    Complex(float, float); //second constructor,
    //all the properties as parameters
    Complex(const Complex &);    //copy constructor
    Complex add(Complex &);      //the methods for addition
    Complex subtract(Complex &); //substraction
    Complex multiply(Complex &); //and multiplications
    ~Complex();                  //destructor
    Complex operator+(Complex);  // added the operator overloading
    Complex operator-(Complex);
    Complex operator*(Complex);
    void operator=(Complex);
    friend std::istream &operator>>(std::istream &in, Complex &z);
    friend std::ostream &operator<<(std::ostream &os, Complex &z);
};