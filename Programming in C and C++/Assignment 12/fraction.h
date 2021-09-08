/*
CH-230-A
a12_p5.h
Antonia Savu
asavu@jacobs-university.de
*/
#ifndef FRACTION_H_
#define FRACTION_H_

class Fraction
{

private:     // internal implementation is hidden
    int num; // numerator
    int den; // denominator

    int gcd(int a, int b); // calculates the gcd of a and b
    int lcm(int a, int b);

public:
    Fraction();             // empty constructor
    Fraction(int, int = 1); // constructor taking values for fractions and
                            // integers. Denominator by default is 1
    void print();           // prints it to the screen
    friend std::istream &operator>>(std::istream &in, Fraction &frac);
    //prototype for overloading the >>
    friend std::ostream &operator<<(std::ostream &os, const Fraction &frac);
    //and the <<
    Fraction operator*(Fraction);
    //also overloading *
    Fraction operator/(Fraction);
    //and / so that they multiply and divide fractions
    Fraction operator+(Fraction); //same with + and -
    Fraction operator-(Fraction);
    void operator=(Fraction);
    //void that assigns a fraction to another(sort of like a copy constructor)
    bool operator>(Fraction);
    bool operator<(Fraction);
    //and finally, booleans that compare two fractions
};
#endif /* FRACTION_H_ */